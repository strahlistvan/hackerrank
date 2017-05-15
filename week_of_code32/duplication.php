<?php

$handle = fopen ("php://stdin", "r");

function negate($str)
{
	$back = "";
	for ($i=0; $i<strlen($str); ++$i)
	{
		$back.=($str[$i] == "0") ? "1" : "0";
	}
	return $back;
}

function generate()
{
	$binary_string = "0";
	while (strlen($binary_string) < 1000)
	{
		$binary_string.=negate($binary_string);
	}
	//echo $binary_string."\n";
	return $binary_string;
}

function duplication($x){
    // Complete this function
	$binary_string = generate();
	return $binary_string[$x];
	
}

fscanf($handle, "%d",$q);
for($a0 = 0; $a0 < $q; $a0++){
    fscanf($handle, "%d",$x);
    $result = duplication($x);
    echo $result . "\n";
}

?>
