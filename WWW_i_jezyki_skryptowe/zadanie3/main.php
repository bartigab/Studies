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
</header>

<aside>

    <form action="index.php" method="post" name="form-login">
        <a name="login_form"></a>
        <header><h2>Zaloguj się do forum</h2></header>  
        <input type="text" name="userid" placeholder="Nazwa logowania" pattern="[A-Za-z0-9\-]*" autofocus \><br />
        <input type="password" name="pass" placeholder="Hasło" \><br/>
        <input type="hidden" name="form-login" value="form-login">
        <button type="submit" >Zaloguj się</button>
    </form>
    <form action="index.php" method="post" name="newuser_form">
        <header><h2>Zarejestruj się do forum</h2></header>  
        <input type="text" name="userid" placeholder="Nazwa logowania" pattern="[A-Za-z0-9\-]*" autofocus \><br />
        <input type="text" name="username" placeholder="Imię autora" \><br />
        <input type="password" name="pass1" placeholder="Hasło" \><br />
        <input type="password" name="pass2" placeholder="Powtórz hasło" \><br />
        <button type="submit" >Zapisz się do forum</button>
    </form>


  
</aside>








</div>
</body>
</html>