<?php
include '../includes/config.php';
include '../includes/functions.php';

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $username = $_POST['username'];
    $password = $_POST['password'];

    $stmt = $pdo->prepare("SELECT * FROM users WHERE username = ?");
    $stmt->execute([$username]);
    $user = $stmt->fetch(PDO::FETCH_ASSOC);

    if ($user && password_verify($password, $user['password'])) {
        $_SESSION['user_id'] = $user['id'];
        $_SESSION['username'] = $user['username'];
        logUserActivity($pdo, $user['id'], 'login');
        header('Location: ../notes.php');
    } else {
        $error = "Nieprawidłowa nazwa użytkownika lub hasło.";
    }
}
?>

<h1>Logowanie</h1>
<form method="post">
    <label for="username">Nazwa użytkownika:</label>
    <input type="text" id="username" name="username" required>
    
    <label for="password">Hasło:</label>
    <input type="password" id="password" name="password" required>
    
    <button type="submit">Zaloguj się</button>
</form>

<?php if (isset($error)): ?>
    <p><?= $error ?></p>
<?php endif; ?>

<?php include '../includes/footer.php'; ?>
