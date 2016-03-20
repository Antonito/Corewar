
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
		include "header.php";
	}
	else {
		echo '<script>window.location.replace("index.php");</script>';
	}
	echo "tous les champions ici";
	$dir = "./bd/";
	$files = scandir($dir); 
	echo "<br>";
	echo "<form action='combat.php' method='post'>";
	echo '<select name="champ[]" multiple="multiple">';
      	echo '<option value="" selected="selected">-----</option>';
	foreach($files as $file)
	{
		if(is_file($dir.$file)){
			echo "<option value='" . $file . "'>".$file."</option>";
		}
	}
	echo "</select>";
	echo "<input type='submit'>";
	echo "</form>";
      ?>
    </p>
  </body>
</html>
