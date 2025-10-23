<?php
include '../includes/config.php';
include '../includes/functions.php';

if (!isLoggedIn()) {
    header('Location: ../index.php');
    exit;
}

$userId = $_SESSION['user_id'];
$noteId = $_POST['id'];
$content = $_POST['content'];

$stmt = $pdo->prepare("UPDATE notes SET content = ? WHERE id = ? AND user_id = ?");
$stmt->execute([$content, $noteId, $userId]);

logUserActivity($pdo, $userId, 'edit_note');

header('Location: ../notes.php');
?>
