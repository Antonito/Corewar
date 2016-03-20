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
		echo "toto";
		echo '<script>window.location.replace("ok.php");</script>';
	}
	else {
        	$login = $_POST['login'];
		$pass = $_POST['pass'];

		$ch = curl_init();
		curl_setopt($ch, CURLOPT_URL,"https://intra.epitech.eu");
		curl_setopt($ch, CURLOPT_POST, 1);
		curl_setopt($ch, CURLOPT_POSTFIELDS,
       	     "login=".$login."&"."password=".$pass);	
		curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
		$server_output = curl_exec ($ch);
		$httpcode = curl_getinfo($ch, CURLINFO_HTTP_CODE);
		curl_close ($ch);
		var_dump($httpcode);
		if ($httpcode == 302){
			echo "connected";
			$_SESSION["login"] = $login;
			echo '<script>window.location.replace("ok.php");</script>';
		}
		else {
			echo '<script>window.location.replace("index.php?fail=1");</script>';
		}
	}
      ?>
    </p>
  </body>
</html>
