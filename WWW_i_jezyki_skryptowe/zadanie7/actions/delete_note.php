<?php
include '../includes/config.php';
include '../includes/functions.php';

if (!isLoggedIn()) {
    header('Location: ../index.php');
    exit;
}

$userId = $_SESSION['user_id'];
$noteId = $_POST['id'];

$stmt = $pdo->prepare("DELETE FROM notes WHERE id = ? AND user_id = ?");
$stmt->execute([$noteId, $userId]);

logUserActivity($pdo, $userId, 'delete_note');

header('Location: ../notes.php');
?>
