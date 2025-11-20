<!DOCTYPE html>
<html>
<head>
    <title>Form Handling in PHP</title>
</head>
<body>
    <h2>Form Handling with GET and POST</h2>

    <form method="post" action="">
        <label>Name:</label>
        <input type="text" name="name"><br><br>

        <label>Email:</label>
        <input type="text" name="email"><br><br>

        <label>Phone:</label>
        <input type="text" name="phone"><br><br>

        <input type="submit" name="submit_post" value="Submit with POST">
    </form>

    <hr>

    <form method="get" action="">
        <label>Name:</label>
        <input type="text" name="name"><br><br>

        <label>Email:</label>
        <input type="text" name="email"><br><br>

        <label>Phone:</label>
        <input type="text" name="phone"><br><br>

        <input type="submit" name="submit_get" value="Submit with GET">
    </form>

    <hr>

    <?php
    function validateInput($name, $email, $phone)
    {
        $errors = [];

        if (empty($name)) {
            $errors[] = "Name cannot be empty.";
        }

        if (empty($email) || !filter_var($email, FILTER_VALIDATE_EMAIL)) {
            $errors[] = "Invalid email format.";
        }

        if (empty($phone) || !preg_match("/^[0-9]{10}$/", $phone)) {
            $errors[] = "Phone must be 10 digits.";
        }

        return $errors;
    }

    if (isset($_POST['submit_post'])) {
        $name = $_POST['name'];
        $email = $_POST['email'];
        $phone = $_POST['phone'];

        $errors = validateInput($name, $email, $phone);

        if (empty($errors)) {
            echo "<h3>Data Submitted with POST:</h3>";
            echo "Name: $name <br>";
            echo "Email: $email <br>";
            echo "Phone: $phone <br>";
        } else {
            echo "<h3>Errors:</h3><ul>";
            foreach ($errors as $err) {
                echo "<li>$err</li>";
            }
            echo "</ul>";
        }
    }

    if (isset($_GET['submit_get'])) {
        $name = $_GET['name'];
        $email = $_GET['email'];
        $phone = $_GET['phone'];

        $errors = validateInput($name, $email, $phone);

        if (empty($errors)) {
            echo "<h3>Data Submitted with GET:</h3>";
            echo "Name: $name <br>";
            echo "Email: $email <br>";
            echo "Phone: $phone <br>";
        } else {
            echo "<h3>Errors:</h3><ul>";
            foreach ($errors as $err) {
                echo "<li>$err</li>";
            }
            echo "</ul>";
        }
    }
    ?>
</body>
</html>
