<?php
include 'db.php';
include 'header.php';

if (!isset($_GET['id'])) {
    echo "<script>alert('Hotel not selected!'); window.location='hotel_city_select.php';</script>";
    exit;
}

$hotel_id = $_GET['id'];

$query = "SELECT hotels.*, cities.city_name 
          FROM hotels 
          JOIN cities ON hotels.city_id = cities.id
          WHERE hotels.id = $hotel_id";

$result = mysqli_query($conn, $query);
$hotel = mysqli_fetch_assoc($result);

if (!$hotel) {
    echo "<script>alert('Invalid Hotel!'); window.location='hotel_city_select.php';</script>";
    exit;
}
?>

<section class="services">
    <h2><?= $hotel['hotel_name'] ?></h2>

    <div class="services-container">

        <div class="service" style="max-width:600px; margin:auto;">

            <img src="images/hotels/<?= $hotel['image'] ?>" 
                 alt="<?= $hotel['hotel_name'] ?>">

            <h3><?= $hotel['hotel_name'] ?></h3>

            <p><b>City:</b> <?= $hotel['city_name'] ?></p>
            <p><b>⭐ Rating:</b> <?= $hotel['star_rating'] ?> Star</p>
            <p><b>Price Per Night:</b> ₹<?= $hotel['price_per_night'] ?></p>

            <p style="margin-top: 1rem;"><?= $hotel['description'] ?></p>

            <a href="hotel_booking.php?id=<?= $hotel['id'] ?>" class="btn" style="margin-top: 1rem;">
                Reserve Now
            </a>

        </div>

    </div>
</section>

<?php
include 'footer.php';
?>
