<?php
include '../includes/config.php';
include '../includes/functions.php';

if (!isLoggedIn()) {
    header('Location: ../index.php');
    exit;
}

$userId = $_SESSION['user_id'];
$content = $_POST['content'];

$stmt = $pdo->prepare("INSERT INTO notes (user_id, content, created_at) VALUES (?, ?, ?)");
$stmt->execute([$userId, $content, date('Y-m-d H:i:s')]);

logUserActivity($pdo, $userId, 'add_note');

header('Location: ../notes.php');
?>
