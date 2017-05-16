<?php

function getMaxMonsters($n, $hit, $time, $monsters){
	$killedMonsters = 0;
	sort($monsters);
	print_r($monsters);
	while ($time > 0)
	{
		while ($monsters[0] > 0)
		{
			$monsters[0]-=$hit;
			echo $killedMonsters." Monster life: ".$monsters[0]."\n";
			--$time;
		}
		unset($monsters[0]);
		$monsters = array_values($monsters);
		++$killedMonsters;
		
		if (count($monsters) === 0) 
			return $killedMonsters;
		
	}
	return $killedMonsters;
}

$monsters = array(0,0,0,16,19,7,11,23,8,16);
$result = getMaxMonsters(7,8,6,$monsters);
echo $result . "\n";

?>