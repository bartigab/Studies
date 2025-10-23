<?php
$path = explode('/',dirname(__FILE__));
$dirname = array_pop($path);
$username = array_pop($path);
$path = implode('/',$path);
$tasks = array();
foreach(scandir( "$path/$username" ) as $dir) if( is_dir("$path/$username/$dir") and $dir!='.' and $dir!='..') $tasks[] = $dir; 
?>
<html>
<head>
  <title>TWWW - User: <?=$username?>, <?=$dirname?></title>
  <meta charset="UTF-8">
  <meta http-equiv="Cache-Control" content="no-store, no-cache, must-revalidate" >
  <meta http-equiv="Pragma" content="no-cache" >
</head>
<body>
<header>
<h1><?=$dirname?></h1>
</header>
<nav>
<a href="<?="/$username"?>" title="Strona początkowa serwisu" target="_self" >Strona początkowa serwisu</a> 
<?php foreach($tasks as $task){ ?>
<a href="<?="/$username/$task"?>/" title="<?=$task?>" target="_self" ><?=$task?></a> 
<?php } ?>
</nav>
<?php
include 'includes/config.php';
include 'includes/functions.php';
include 'includes/header.php';

registerGuestVisit($pdo);

$notes = getAllNotes($pdo);
?>

<h1>Notatki</h1>

<ul>
    <?php foreach ($notes as $note): ?>
        <li><a href="note_view.php?id=<?= $note['id'] ?>">
            <?= substr($note['content'], 0, 10) ?>
        </a></li>
    <?php endforeach; ?>
</ul>
<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <title>Rejestracja</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>

<?php include 'includes/footer.php'; ?>

</body>
</html>