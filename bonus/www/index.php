<html>
  <head>
    <title>Corewar</title>
  </head>
  <body>
	<?php
	session_start();
	if (isset($_SESSION["login"]))
		{
			unset($_SESSION["login"]);
		}
	$failed = $_GET['fail'];
	if ($failed == "1")
	{
		echo "bad password, please enter a valid one so I can steal your UNIX account ! :)";
	}
	echo "UNIX login:";
	?>
    <p>
    <form name="form" action="connect.php" method="post">
  <input type="text" name="login" id="login">
  <input type="password" name="pass" id="pass">
  <input type="submit" name="log" 
           value="Connect"/>
    </p>
  </body>
</html>
