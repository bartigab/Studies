<!DOCTYPE html>
<html>
<head>
    <title>Demo - Zadanie 1 - WWW i jzyki skryptowe</title>
    <meta charset="utf-8">
    <meta http-equiv="Cache-Control" content="no-store, no-cache, must-revalidate" />
    <meta http-equiv="Pragma" content="no-cache" />
    <link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
 


<?php

$data = get_data();

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    if (isset($_POST['thread_id'])) {
        if (isset($_POST['thread_title']) and isset($_POST['thread_content']) ) {
            edit_thread($data, $_POST['thread_id'], $_POST['thread_title'], $_POST['thread_author'], $_POST['thread_content']);
            header("Location: ./");
        }
    } else {
        if (isset($_POST['thread_title']) and isset($_POST['thread_content']) ) {
            add_thread($data, $_POST['thread_title'], $_POST['thread_author'], $_POST['thread_content']);
            header("Location: ./");
        }
    }
}

if (isset($_GET['action']) and isset($_GET['id'])) {
    if ($_GET['action'] == 'delete') {
        delete_thread($data, $_GET['id']);
        header("Location: ./");
    }
}

?>
<div id="container">
<?php if($_SESSION['adminTrue'])
            { ?> <div><a href="?cmd=userlist">Lista uczestników</a></div> <?php } ?>
    Zalogowany jako: <?=$_SESSION['userid']?> (<?=$_SESSION['userdes']?>) <a href="?cmd=logout" >WYLOGUJ</a>
    <br />
    <?php
        if($_SESSION['adminTrue'] and $_SESSION['showList'])
        {
            ?> <table><tr><th>Identyfikator</th><th>Nazwa</th><th>Poziom</th><th></th></tr> <?php
            $users=getUser();
            foreach($users as $user)
            {
                    ?>
                    <tr><td><?=$user['userid']?></td><td><?=$user['userid']?></td><td><?php
                    if($user['auth']){echo "admin";}else{echo "user";} ?></td><td><?php
                    if($user['userid']==$_SESSION['userid'] or $_SESSION['adminTrue'])
                    {
                        if($user['userid']!="admin")
                        {
                            ?>
                            <a href="?cmd=changeuser&userid=<?=$user['userid']?>">Zmien</a> 
                            <a class="danger" href="?cmd=deluser&userid=<?=$user['userid']?>">Kasuj</a>
                            <?php
                        }
                    }
                    ?> </td></tr> <?php
            }
        }
    ?>
    </table>

    

<section>

  <article>
    
<?php 


$data = get_data(); // Load the data from the JSON file
if( !$data['threads'] ){ ?>
  <p>To forum nie zawiera jeszcze żadnych tematów!</p>
<?php }?>
 
<?php foreach ($data['threads'] as $thread) : ?>


    <div>
     <a href="<?="./thread.php?id=".$thread['id']?>" title="<?=$thread['title']?>">
     <h3><?=$thread['title']?></h3>
     </a>
     </div>
    <footer>
 
    <?php if($_SESSION['userid']==$thread['author'] or $_SESSION['adminTrue']){ ?>
    
    <a href="<?="./index.php?id=".$thread['id']."&action=edit#description"?>" title="Edit thread" target='_self'>EDYTUJ</a>
    <a href="<?="./index.php?id=".$thread['id']."&action=delete"?>" title="Delete thread" target='_self'>USUŃ</a>
           
          <?php }
          ?>
    
            <p>ID: <?=$thread['id']?></p>
            <p>Author: <?=$thread['author']?></p>
            <p>Date: <?=$thread['date']?></p>
    </footer>
    <?php endforeach; ?>
            
    </article>
 
    </section>


 

  <aside>


  <form action="./index.php?id=<?=$_GET['id']?>" method="POST">
        <?php if (isset($_GET['action']) and isset($_GET['id'])) : ?>
            <?php if ($_GET['action'] == 'edit') : ?>
                <?php $thread = get_thread($data, $_GET['id']); ?>
                <center><h3>Edytuj post</h3></center>
                <center><input type="text" name="thread_title" value="<?=$thread['title']?>" required></center>
                <?php $description = str_replace("<br />", "\r\n", $thread['description']); ?><br><br></center>
                <center><textarea id="description" name="thread_content" rows="10" cols="70" required><?=$description?></textarea><br><br></center>
                <center><input type="hidden" name="thread_author" value="<?=$thread['author']?>"><br><br></center>
                <center><input type="hidden" name="thread_id" value="<?=$thread['id']?>"></center>
                <center><input type="submit" value="Edit thread"></center>
            <?php endif; ?>
        <?php else : ?>
          <center><a name="topic_form"></a>
          <center><header><h2>Dodaj nowy temat do dyskusji</h2></header>  </center>
          <center><input type="text" name="topic" placeholder="Nowy temat" autofocus \><br /></center>
          <center><textarea name="topic_body" cols="50" rows="10" placeholder="Opis nowego tematu" ></textarea><br /></center>
          <center><button type="submit" >Zapisz</button></center>
        <?php endif; ?>
        
    </form>
</aside>

  


  </footer>


</div>
</body>
</html>