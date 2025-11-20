<?php
include 'db.php';
include 'header.php';

$message = "";

if ($_SERVER["REQUEST_METHOD"] == "POST")
{
    $name = $_POST['name'];
    $contact = $_POST['contact'];
    $email = $_POST['email'];
    $from_city = $_POST['from_city'];
    $to_city = $_POST['to_city'];
    $travel_date = $_POST['travel_date'];
    $insurance = $_POST['insurance'];

    $sql = "INSERT INTO flight_bookings (name, contact, email, from_city, to_city, travel_date, insurance)
            VALUES ('$name', '$contact', '$email', '$from_city', '$to_city', '$travel_date', '$insurance')";

    if (mysqli_query($conn, $sql))
    {
        $message = "Booking successful!";
    }
    else
    {
        $message = "Error: " . mysqli_error($conn);
    }
}
?>

<section class="contact">
    <h2>Flight Booking</h2>

    <?php if ($message != "") { ?>
        <p style="color: green; font-weight: bold;"><?= $message ?></p>
    <?php } ?>

    <form method="POST">

        <label>Name:</label>
        <input type="text" name="name" required>

        <label>Contact:</label>
        <input type="text" name="contact" required>

        <label>Email:</label>
        <input type="email" name="email" required>

        <label>From City:</label>
        <input type="text" name="from_city" required>

        <label>To City:</label>
        <input type="text" name="to_city" required>

        <label>Travel Date:</label>
        <input type="date" name="travel_date" required>

        <label>Travel Insurance:</label>
        <select name="insurance">
            <option value="No">No</option>
            <option value="Yes">Yes (+₹499)</option>
        </select>

        <center>
            <button type="submit" class="btn">Book Flight</button>
        </center>

    </form>
</section>

<?php
include 'footer.php';
?>
