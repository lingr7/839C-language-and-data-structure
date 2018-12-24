var clr=["CF","DF","EF","FF","C7","D7","E7","F7"];
function changeColorStr()
{
  s="#"+clr[Math.floor(Math.random()*clr.length)];
  s+=clr[Math.floor(Math.random()*clr.length)];
  s+=clr[Math.floor(Math.random()*clr.length)]; 
  return s;
}
function changebgColor(cName)
{
  var e=document.getElementsByClassName(cName);
  for(var i=0;i<e.length;i++)
  	e[i].style="background-color:"+changeColorStr()+";";
}
changebgColor("qtitle");

