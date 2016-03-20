<html>
  <head>
    <title>My First Array</title>
  </head>
  <body>
    <p>
      <?php
	ini_set('display_errors', 'On');
	error_reporting(E_ALL);
	session_start();
	if (isset($_SESSION["login"]))
	{
		echo $_SESSION["login"];
	}
	else {
		echo '<script>window.location.replace("index.php");</script>';
	}
	$name = $_GET['file'];
	$target_dir = __DIR__ ."/bd/".$_SESSION["login"]."/";
	echo "compilation de ".$name;
	echo shell_exec("cat ".$target_dir.$name);

      ?>
    </p>
  </body>
</html>
