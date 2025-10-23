<?php
include 'includes/config.php';
include 'includes/functions.php';
include 'includes/header.php';
if (!isLoggedIn()) {
    header('Location: index.php');
    exit;
}

$userId = $_SESSION['user_id'];
logUserActivity($pdo, $userId, 'view_notes');
$notes = getUserNotes($pdo, $userId);
?>

<h1>Moje Notatki</h1>

<form method="post" action="actions/add_note.php">
    <textarea name="content" placeholder="Dodaj nową notatkę" required></textarea>
    <button type="submit">Dodaj</button>
</form>

<ul>
    <?php foreach ($notes as $note): ?>
        <li>
            <form method="post" action="actions/edit_note.php">
                <textarea name="content" required><?= $note['content'] ?></textarea>
                <input type="hidden" name="id" value="<?= $note['id'] ?>">
                <button type="submit">Edytuj</button>
            </form>
            <form method="post" action="actions/delete_note.php" onsubmit="return confirm('Czy na pewno chcesz usunąć notatkę?');">
                <input type="hidden" name="id" value="<?= $note['id'] ?>">
                <button type="submit">Usuń</button>
            </form>
        </li>
    <?php endforeach; ?>
</ul>

<?php include 'includes/footer.php'; ?>
