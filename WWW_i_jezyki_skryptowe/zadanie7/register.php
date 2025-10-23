<?php
include 'includes/config.php';
include 'includes/functions.php';
include 'includes/header.php';

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $username = $_POST['username'];
    $firstname = $_POST['firstname'];
    $lastname = $_POST['lastname'];
    $password = password_hash($_POST['password'], PASSWORD_DEFAULT);

    $stmt = $pdo->prepare("INSERT INTO users (username, firstname, lastname, password) VALUES (?, ?, ?, ?)");
    $stmt->execute([$username, $firstname, $lastname, $password]);

    header('Location: login.php');
}

?>

<h1>Rejestracja</h1>
<form method="post">
    <label for="username">Nazwa użytkownika:</label>
    <input type="text" id="username" name="username" required>
    
    <label for="firstname">Imię:</label>
    <input type="text" id="firstname" name="firstname" required>
    
    <label for="lastname">Nazwisko:</label>
    <input type="text" id="lastname" name="lastname" required>
    
    <label for="password">Hasło:</label>
    <input type="password" id="password" name="password" required>
    
    <button type="submit">Zarejestruj się</button>
</form>

<?php include 'includes/footer.php'; ?>
