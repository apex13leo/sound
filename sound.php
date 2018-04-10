<?php
$log_file = 'sound_log.txt';
$data = $_POST['data'];
$today = date("Y-m-d H:i:s");
$str = $today .', '.$data."\n";
//now we open the file
echo "Data is stored\n";
if(file_exists($log_file)){
	$fp=fopen($log_file, "a"); //the file is opened as append mode
	fwrite($fp, $str);
	fpclose($fp);
}else{		//the file doesn't exist, so open a new one
	$fp = fopen($log_file, "w");
	fwrite($fp, $str);
	fclose($fp);
}

?>