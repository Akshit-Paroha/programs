<?php
include 'db.php';
include 'header.php';

if (!isset($_GET['city_id'])) {
    echo "<script>alert('City not selected!'); window.location='hotel_city_select.php';</script>";
    exit;
}

$city_id = $_GET['city_id'];

$city_query = "SELECT city_name FROM cities WHERE id = $city_id";
$city_result = mysqli_query($conn, $city_query);
$city = mysqli_fetch_assoc($city_result)['city_name'];
?>

<section class="services">
    <h2>Hotels in <?= $city ?></h2>

    <div class="services-container">

        <?php
        $query = "SELECT * FROM hotels WHERE city_id = $city_id ORDER BY star_rating DESC";
        $result = mysqli_query($conn, $query);

        while ($hotel = mysqli_fetch_assoc($result)) {
            echo "
            <div class='service'>
                <img src='images/hotels/" . $hotel['image'] . "' alt='" . $hotel['hotel_name'] . "'>

                <h3>" . $hotel['hotel_name'] . "</h3>
                <p><b>⭐ " . $hotel['star_rating'] . " Star Hotel</b></p>
                <p>₹" . $hotel['price_per_night'] . " / night</p>

                <a href='hotel_details.php?id=" . $hotel['id'] . "' class='btn'>View Details</a>
            </div>
            ";
        }
        ?>

    </div>
</section>

<?php
include 'footer.php';
?>
