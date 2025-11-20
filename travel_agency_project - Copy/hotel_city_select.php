<?php
include 'db.php';
include 'header.php';
?>

<section class="contact">
    <h2>Select City</h2>

    <form method="GET" action="hotel_list.php">

        <label>Select a City:</label>
        <select name="city_id" required>
            <option value="">-- Choose City --</option>

            <?php
            $query = "SELECT * FROM cities ORDER BY city_name ASC";
            $result = mysqli_query($conn, $query);

            while($row = mysqli_fetch_assoc($result))
            {
                echo "<option value='" . $row['id'] . "'>" . $row['city_name'] . "</option>";
            }
            ?>
        </select>

        <center>
            <button type="submit" class="btn">Next</button>
        </center>

    </form>
</section>

<?php
include 'footer.php';
?>
