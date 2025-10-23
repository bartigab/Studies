<?php
$path = explode('/',dirname(__FILE__));
$dirname = array_pop($path);
$username = array_pop($path);
$path = implode('/',$path);
$tasks = array();
foreach(scandir( "$path/$username" ) as $dir) if( is_dir("$path/$username/$dir") and $dir!='.' and $dir!='..') $tasks[] = $dir; 

?>
<!DOCTYPE html>
<html>
<head>  
    <link rel="stylesheet" href="style.css">
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
<?php } 
?>
</nav>
<header id="blog"><h1>Mój blog</h1></header>

<?php
   

 



   include('data.php');

        session_start();
        if (!isset($_SESSION['errortxt'])) {$_SESSION['errortxt'] = null;}
        if (!isset($_SESSION['userid'])) {$_SESSION['userid'] = null;}
        if (!isset($_SESSION['userdes'])) {$_SESSION['userdes'] = null;}
        if (!isset($_SESSION['showList'])) {$_SESSION['showList'] = false;}
        $_SESSION['adminTrue']=false;



                

        



        $user_file = "users.json";
        // Check if admin exists
        $users = getUser();
        $adminExists = false;

        foreach($users as $user)
        {
            if($user['userid'] == 'admin')
            {
                $adminExists = true;
                break;
            }
        }

        // If admin does not exist, create admin
        if(!$adminExists)
        {
            setUserToDB('admin', 'admin', 'admin', '1', 'users.json');
        }



     //czy jest adminem
        if($_SESSION['userid'])
            {
                
                if(checkAdmin($_SESSION['userid']))
                    $_SESSION['adminTrue']=true;
            }
        
        //NEW USER ADDING
        if(isset($_POST['username']) and $_POST['userid']!='' and $_POST['pass1']!='' and $_POST['pass2']!='')
        {
            if($_POST['pass1'] == $_POST['pass2'])
            {
                $users = getUser();
                $tmpNoUser = false;
                foreach($users as $user)
                {
                    if($_POST['userid'] == $user['userid'])
                    {
                        $tmpNoUser = true;
                        break;
                    }
                }
                if(!$tmpNoUser)
                {
                    // Set auth to '0' for all new users, except for 'admin'
                    $auth = ($_POST['userid'] == 'admin') ? '1' : '0';
                    setUserToDB($_POST['userid'], $_POST['username'], $_POST['pass1'], $auth, 'users.json');
                    $_SESSION['userid'] = $_POST['userid'];
                    header("Location: index.php");
                }
            }
        }

// LOGIN ATTEMPT
if(isset($_POST['userid']) && isset($_POST['pass']))
{
    $userdes = tryLogin($_POST['userid'], $_POST['pass']);
    if($userdes !== False)
    {
        // Login successful, set the session variables
        $_SESSION['userid'] = $_POST['userid'];
        $_SESSION['userdes'] = $userdes;
        header("Location: index.php");
    }
    else
    {
        // Login failed, set an error message
        $_SESSION['errortxt'] = "ZŁE DANE LOGOWANIA";
    }
}

      
$data = json_decode(file_get_contents('data.json'), true);

// Add a new topic
if (isset($_POST['topic']) && $_POST['topic'] != "" && $_POST['topic_body'] != "") {
    add_thread($data, $_POST['topic'], $_SESSION['userid'], $_POST['topic_body']);
    header("Location: index.php");
    exit;
}

// Add or update a post
if (isset($_POST['post']) && $_POST['post'] != "") {
    if ($_POST['postid'] != '') {
        edit_thread($data, $_POST['postid'], $_GET['topic'], $_SESSION['userid'], $_POST['post']);
    } else {
        add_thread($data, $_GET['topic'], $_SESSION['userid'], $_POST['post']);
    }
    header("Location: index.php?topic=" . $_GET['topic']);
    exit;
}

// Delete a post
if (isset($_GET['cmd']) && $_GET['cmd'] == "delete" && $_GET['id'] != "" && $_GET['topic'] != "") {
    delete_thread($data, $_GET['id']);
    header("Location: index.php?topic=" . $_GET['topic']);
    exit;
}

// Get post data for editing
if (isset($_GET['cmd']) && $_GET['cmd'] == "edit" && $_GET['id'] != "" && $_GET['topic'] != "") {
    $post = get_thread($data, $_GET['id']);
} else {
    $post = false;
}

// Get all topics
$topics = $data['threads'];

// Delete a topic
if (isset($_GET['cmd']) && $_GET['cmd'] == "deleteTopic" && $_GET['id'] != "") {
    delete_thread($data, $_GET['id']);
    header("Location: index.php");
    exit;
}
// Load the data from the JSON file
$data = get_data();

if($_SESSION['userid'])
{
    if( isset($_GET["topic"]) and $_GET["topic"]!='' )
    {  
       $posts = get_thread($data, $_GET["topic"])['posts'];
       $topic= get_thread($data, $_GET["topic"]);
       include('tematy.php');
    }
    else
    {
         $posts_count = count($data['threads']);
         include('tematy.php'); 
    }
    if(isset($_GET['cmd']))
    {
        if($_GET['cmd']=="logout")
        {
            $_SESSION = array();
            if (ini_get("session.use_cookies"))
            {
                $params = session_get_cookie_params();
                setcookie(session_name(), '', time() - 42000,
                    $params["path"], $params["domain"],
                    $params["secure"], $params["httponly"]
                    );
            }
            session_unset();
            session_destroy();
            header("Location: ./");
        }
        if($_GET['cmd'])
        {
            if($_GET['cmd']=="changeuser")
            {
                updateUserAuth($_GET['userid']);
                header("Location: index.php");
            }
            else if($_GET['cmd']=="deluser")
            {
                deleteUser($_GET['userid']);
                header("Location: index.php");
            }
            else if($_GET['cmd']=="userlist")
            {
                if($_SESSION['showList'])
                {
                    $_SESSION['showList']=false;
                    header("Location: index.php");
                }
                else
                {
                    $_SESSION['showList']=true;
                    header("Location: index.php");
                }
            }
        }
    }
}
else
{
    include('main.php');
}


?>













<footer id="dol">
    Stopka wiadomości: TWWW - User: <?=$username?>
<p>Stopka dokumentu: TWWW - IR - WIiT PP - <?=date("Y")?></p>
</footer>


</div>
</body>
</html>