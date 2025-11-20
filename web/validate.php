<!DOCTYPE HTML>
<html>

<head>
    <title>Event Registration Form</title>
</head>

<body>

    <?php
    $name = $email = $phone = "";
    $nameErr = $emailErr = $phoneErr = "";

    if ($_SERVER["REQUEST_METHOD"] == "POST" || $_SERVER["REQUEST_METHOD"] == "GET") 
    {
        if (empty($_REQUEST["name"])) {
            $nameErr = "Name is required";
        } else {
            $name = test_input($_REQUEST["name"]);
        }

        if (empty($_REQUEST["email"])) {
            $emailErr = "Email is required";
        } else {
            $email = test_input($_REQUEST["email"]);
            if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
                $emailErr = "Invalid email format";
            }
        }

        if (empty($_REQUEST["phone"])) {
            $phoneErr = "Phone is required";
        } else {
            $phone = test_input($_REQUEST["phone"]);
            if (!preg_match("/^[0-9]{10}$/", $phone)) {
                $phoneErr = "Invalid phone number (10 digits required)";
            }
        }
    }

    function test_input($data)
    {
        $data = trim($data);
        $data = stripslashes($data);
        $data = htmlspecialchars($data);
        return $data;
    }
    ?>

    <h2>Event Registration Form</h2>
    <p><span style="color:red;">* required field</span></p>

    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>">
        Name: <input type="text" name="name" value="<?php echo $name; ?>">
        <span style="color:red;">* <?php echo $nameErr; ?></span>
        <br><br>
        E-mail: <input type="text" name="email" value="<?php echo $email; ?>">
        <span style="color:red;">* <?php echo $emailErr; ?></span>
        <br><br>
        Phone: <input type="text" name="phone" value="<?php echo $phone; ?>">
        <span style="color:red;">* <?php echo $phoneErr; ?></span>
        <br><br>
        <input type="submit" value="Register with POST">
    </form>

    <br><br>

    <form method="get" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>">
        Name: <input type="text" name="name">
        <br><br>
        E-mail: <input type="text" name="email">
        <br><br>
        Phone: <input type="text" name="phone">
        <br><br>
        <input type="submit" value="Register with GET">
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST" || $_SERVER["REQUEST_METHOD"] == "GET") {
        if (empty($nameErr) && empty($emailErr) && empty($phoneErr)) {
            echo "<h2>Submitted Data (via " . $_SERVER["REQUEST_METHOD"] . "):</h2>";
            echo "Name: " . $name . "<br>";
            echo "Email: " . $email . "<br>";
            echo "Phone: " . $phone . "<br>";
        }
    }
    ?>

</body>

</html>