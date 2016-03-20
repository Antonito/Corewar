
<html>
  <head>
    <title>My First Array</title>
  </head>
  <body>
    <p>
      <?php
	session_start();
	if (isset($_SESSION["login"]))
	{
		echo $_SESSION["login"]."<br>";
	}
	else {
		echo '<script>window.location.replace("index.php");</script>';
	}	
	echo "Champs are fighting, Poc est un caca <3<br>";
	foreach ($_POST['champ'] as $selectedOption)
		    echo $selectedOption."<br>";
      ?>
    </p>
  </body>
</html>
