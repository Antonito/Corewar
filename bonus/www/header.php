<html>
  <head>
    <title>Corewar</title>
    <link rel="stylesheet" type="text/css" href="style.css">
	<link rel='shortcut icon' type='image/x-icon' href='imgs/favicon.png'/>
  </head>
  <body>
<video autoplay loop poster="polina.jpg" id="bgvid">
    <source src="polina.webm" type="video/webm">
    <source src="nico.mp4" type="video/mp4">
</video>
    <p>
      <?php
	session_start();
	if (isset($_SESSION["login"]))
	{
		echo "";
	}
	else {
		echo '<script>window.location.replace("index.php");</script>';
	}	


	$dir = "/home/tekdoom/CPE_2015_corewar/bonus/www/bd/";
	$files = scandir($dir); 
	echo "<br>";
	echo "<form class='box' action='combat.php' method='POST'>";
	echo '<select name="champ[]" multiple="multiple">';
	$res = scandir($dir.$_SESSION['login']);
	$user_file = $res[2]; 
	if ($user_file != "")
		echo "<option value='" .$dir.$_SESSION['login']. "/".$user_file . "'>".$_SESSION['login']."/".$user_file."</option>";
	foreach($files as $file)
	{
		if(is_file($dir.$file)){
			echo "<option value='" . $dir.$file . "'>".$file."</option>";
		}
	}
	$files = array_diff($files, array('.', '..'));
	foreach($files as $file)
	{
		if(!is_file($dir.$file) && file != ".."){
			$res = scandir($dir.$file);
			$user_file = $res[2]; 
			$res = scandir($dir.$file);
			$user_file = $res[2]; 
			if ($user_file != "")
				echo "<option value='" .$dir.$file. "/".$user_file . "'>".$file."/".$user_file."</option>";
			}
		}
	echo "</select>";
	echo '<div class="ok">';
    	echo '<label for="ok">';
		echo '<img class="fight" src="imgs/fight.png" alt="fight">';
    	echo '</label>';
    	echo '<input name="ok" id="ok" type="submit" />';
	echo '</div>';
	echo "</form>";




		$bite ="mkdir bd/".$_SESSION['login'];
		if (!file_exists($bite)) {
		$res = shell_exec($bite." 2>&1");
		}
		$target_dir = __DIR__ ."/bd/".$_SESSION["login"]."/";

		$valid_formats = array("s", "cor");
		$max_file_size = 1024*100; //100 kb
		$path = $target_dir; // Upload directory

		if(isset($_POST) and $_SERVER['REQUEST_METHOD'] == "POST" and !$_POST['champ'][0]){
			$name = $_FILES['file']['name'];
	    	if ($_FILES['file']['error'] == 0) {	           
	        	if ($_FILES['file']['size'] > $max_file_size) {
	            		$message[] = "$name is too large!.";
				echo '<script>window.location.replace("ok.php");</script>';
	        	}
			elseif( ! in_array(pathinfo($name, PATHINFO_EXTENSION), $valid_formats) ){
				$message[] = "$name is not a valid format";
				echo '<script>window.location.replace("ok.php");</script>';
			}
	        else{ // No error found! Move uploaded files 
			$res = shell_exec("cd /home/tekdoom/CPE_2015_corewar/bonus/www/bd/".$_SESSION["login"].";rm -rf *");
	            if(move_uploaded_file($_FILES["file"]["tmp_name"], $path.$name)){
			    if (pathinfo($name, PATHINFO_EXTENSION) == 's')
			    { 
				echo "<div class='compile'>Compilation finie<br></div>";
				$res = shell_exec("cd /home/tekdoom/CPE_2015_corewar/bonus/www/bd/".$_SESSION["login"].";../../../../asm/asm *");
				$res = shell_exec("cd /home/tekdoom/CPE_2015_corewar/bonus/www/bd/".$_SESSION["login"].";rm -rf *.s");
			    }
			    else
			    {
				echo '<script>window.location.replace("ok.php");</script>';
			    }
		    }
	        }
	    }
}




      ?>
    </p>
  </body>
 <footer class="footer">
	<form id="form" action="" method="POST" enctype="multipart/form-data">
	<div class="image-upload">
    	<label for="file">
		<img class="upload" src="imgs/upload.png" alt="upload">
    	</label>
    	<input name="file" id="file" type="file" onchange="javascript:this.form.submit();"/>
	</div>
	</form>
	<a href="rank.php"><img class="rank" src="imgs/rank.png" alt="rank"></a>
	<a href="index.php"><img class="logout" src="imgs/logout.png" alt="logout"></a>
	<img class="horizontal_leek" src="imgs/horizontal_leek.png" alt="Super poireau">
 </footer>
</html>
