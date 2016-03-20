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
	echo "uploading files";
}
else {
	echo '<script>window.location.replace("index.php");</script>';
}	
$bite ="mkdir bd/".$_SESSION['login'];
var_dump($bite);
if (!file_exists($bite)) {
	$res = shell_exec($bite." 2>&1");
	var_dump($res);
}
$target_dir = __DIR__ ."/bd/".$_SESSION["login"]."/";

$valid_formats = array("s", "cor");
$max_file_size = 1024*100; //100 kb
$path = $target_dir; // Upload directory

if(isset($_POST) and $_SERVER['REQUEST_METHOD'] == "POST"){
	// Loop $_FILES to exeicute all files
	$name = $_FILES['file']['name'];
	    if ($_FILES['file']['error'] == 0) {	           
	        if ($_FILES['file']['size'] > $max_file_size) {
	            $message[] = "$name is too large!.";
	        }
			elseif( ! in_array(pathinfo($name, PATHINFO_EXTENSION), $valid_formats) ){
				$message[] = "$name is not a valid format";
			}
	        else{ // No error found! Move uploaded files 
			$res = shell_exec("cd /home/tekdoom/CPE_2015_corewar/bonus/www/bd/".$_SESSION["login"].";rm -rf *");
	            if(move_uploaded_file($_FILES["file"]["tmp_name"], $path.$name)){
			    if (pathinfo($name, PATHINFO_EXTENSION) == 's')
			    { 
				echo "Compilation du champion en cours<br>";
				$res = shell_exec("cd /home/tekdoom/CPE_2015_corewar/bonus/www/bd/".$_SESSION["login"].";../../../../asm/asm *");
				$res = shell_exec("cd /home/tekdoom/CPE_2015_corewar/bonus/www/bd/".$_SESSION["login"].";rm -rf *.s");
				echo '<script>window.location.replace("all.php");</script>';
			    }
			    else
			    {
				echo '<script>window.location.replace("all.php");</script>';
			    }
		    }
	        }
	    }
}
?>
		</p>
	</body>
</html>
