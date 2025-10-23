<?php
include 'includes/config.php';
include 'includes/functions.php';
include 'includes/header.php';
registerGuestVisit($pdo);

$noteId = $_GET['id'];

$stmt = $pdo->prepare("SELECT notes.content, notes.created_at, users.firstname, users.lastname 
                       FROM notes 
                       JOIN users ON notes.user_id = users.id 
                       WHERE notes.id = ?");
$stmt->execute([$noteId]);
$note = $stmt->fetch(PDO::FETCH_ASSOC);
?>

<h1><?= $note['firstname'].' '.$note['lastname'] ?></h1>
<p><?= $note['content'] ?></p>
<p><em><?= $note['created_at'] ?></em></p>

<?php include 'includes/footer.php'; ?>
