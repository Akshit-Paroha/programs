<?php
session_start();
$conn = new mysqli("localhost", "root", "", "travel_agency");

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

if (!isset($_GET['hotel_id'])) {
    die("Invalid Access");
}

$hotel_id = $_GET['hotel_id'];

$sql = "SELECT hotels.id, hotels.hotel_name, hotels.address, hotels.description, hotels.rating, hotels.price_per_night, cities.city_name
        FROM hotels
        JOIN cities ON hotels.city_id = cities.id
        WHERE hotels.id = $hotel_id";

$result = $conn->query($sql);

if ($result->num_rows == 0) {
    die("Hotel not found");
}

$hotel = $result->fetch_assoc();

if ($_SERVER['REQUEST_METHOD'] == 'POST') {

    $full_name = $_POST['full_name'];
    $phone = $_POST['phone'];
    $email = $_POST['email'];
    $checkin = $_POST['checkin'];
    $checkout = $_POST['checkout'];
    $rooms = $_POST['rooms'];
    $insurance = isset($_POST['insurance']) ? 1 : 0;

    $insert = "INSERT INTO hotel_bookings (hotel_id, full_name, phone, email, checkin_date, checkout_date, rooms, travel_insurance)
               VALUES ('$hotel_id', '$full_name', '$phone', '$email', '$checkin', '$checkout', '$rooms', '$insurance')";

    if ($conn->query($insert)) {
        $_SESSION['success'] = "Hotel Reserved Successfully!";
        header("Location: services.php");
        exit();
    } else {
        echo "Error: " . $conn->error;
    }
}

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Hotel Reservation</title>
    <link rel="stylesheet" href="styles.css">
    <style>
        .hotel-box { width: 60%; margin:auto; background:white; padding:25px; border-radius:10px; }
        input, select { width:100%; padding:10px; margin:8px 0; }
        button { padding: 12px 20px; background:#3498db; color:white; border:none; border-radius:5px; cursor:pointer; }
        button:hover { background:#217dbb; }
    </style>
</head>
<body>

<div class="hotel-box">
    <h2><?php echo $hotel['hotel_name']; ?> (<?php echo $hotel['rating']; ?>★)</h2>
    <p><strong>City:</strong> <?php echo $hotel['city_name']; ?></p>
    <p><strong>Address:</strong> <?php echo $hotel['address']; ?></p>
    <p><?php echo $hotel['description']; ?></p>
    <p><strong>Price per Night:</strong> ₹<?php echo $hotel['price_per_night']; ?></p>

    <hr>

    <h3>Reserve This Hotel</h3>

    <form method="POST">
        <label>Full Name</label>
        <input type="text" name="full_name" required>

        <label>Phone Number</label>
        <input type="text" name="phone" required>

        <label>Email Address</label>
        <input type="email" name="email" required>

        <label>Check-in Date</label>
        <input type="date" name="checkin" required>

        <label>Check-out Date</label>
        <input type="date" name="checkout" required>

        <label>Number of Rooms</label>
        <input type="number" name="rooms" min="1" required>

        <label>
            <input type="checkbox" name="insurance"> Add Travel Insurance (optional)
        </label>

        <button type="submit">Reserve Hotel</button>
    </form>
</div>

</body>
</html>
