<?php
session_start();

$conn = new mysqli("localhost", "root", "", "travel_agency");

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$success = "";

if ($_SERVER["REQUEST_METHOD"] === "POST") {

    $full_name = $_POST["full_name"];
    $email = $_POST["email"];
    $phone = $_POST["phone"];
    $message = $_POST["message"];

    $sql = "INSERT INTO contacts (full_name, email, phone, message)
            VALUES ('$full_name', '$email', '$phone', '$message')";

    if ($conn->query($sql)) {
        $success = "Your message has been sent successfully!";
    } else {
        $success = "Error: " . $conn->error;
    }
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Contact Us</title>
    <link rel="stylesheet" href="styles.css">
    <style>
        .contact-box {
            width: 50%;
            margin: auto;
            background: white;
            padding: 25px;
            border-radius: 10px;
        }
        input, textarea {
            width: 100%;
            padding: 10px;
            margin: 8px 0;
        }
        button {
            padding: 12px 20px;
            background: #27ae60;
            color: white;
            border: none;
            border-radius: 5px;
            cursor: pointer;
        }
        button:hover {
            background: #1e874b;
        }
        .msg {
            background: #dff0d8;
            padding: 10px;
            margin-top: 10px;
            border-left: 5px solid #3c763d;
        }
    </style>
</head>
<body>

<div class="contact-box">
    <h2>Contact Us</h2>

    <?php if ($success !== ""): ?>
        <div class="msg"><?php echo $success; ?></div>
    <?php endif; ?>

    <form method="POST">
        <label>Full Name</label>
        <input type="text" name="full_name" required>

        <label>Email Address</label>
        <input type="email" name="email" required>

        <label>Phone Number</label>
        <input type="text" name="phone" required>

        <label>Your Message</label>
        <textarea name="message" rows="5" required></textarea>

        <button type="submit">Submit</button>
    </form>
</div>

</body>
</html>
