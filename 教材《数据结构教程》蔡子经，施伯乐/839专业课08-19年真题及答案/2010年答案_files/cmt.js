
    function showCMT()
    {
        if(document.getElementById("cmtSpace").style.display=='none')
            document.getElementById("cmtSpace").style.display="inline";
        else
            document.getElementById("cmtSpace").style.display='none';
    }
var countTime=0;
function changeTimeCounter()
    {
        if(countTime>0){
            countTime--;
            setTimeout("changeTimeCounter()",1000);
        }
    }
function timeGap()
{
    if(countTime==0){
        countTime=20;
        changeTimeCounter();
        return true;
    }
    else
        return false;
}
    function loadXMLDoc()
    {
      var nickName=document.getElementById("nickName").value
      var comment=document.getElementById("comment").value;
      nickName=nickName.replace(/\+/g,'%2B');
      nickName=nickName.replace(/\&/g,"%26");
      comment=comment.replace(/\+/g,'%2B');
      comment=comment.replace(/\&/g,"%26");

        if(nickName.length<4)
            alert("你的..太短，昵称至少4个字符");
        else if(comment.length<5)
            alert("你的..太短，请适当丰富内容后再发送");
        else
        {
    if(timeGap()==true)
    {
      var xmlhttp;
      xmlhttp=new XMLHttpRequest();
      
      xmlhttp.onreadystatechange=function()
      {
        if (xmlhttp.readyState==4 && xmlhttp.status==200)
        {
          document.getElementById("cmt").innerHTML=xmlhttp.responseText;
        }
      }
      xmlhttp.open("POST","upldCMT.php",true);
      xmlhttp.setRequestHeader("Content-type","application/x-www-form-urlencoded");

      xmlhttp.send("nickName="+nickName +"&comment="+comment);
      document.getElementById("nickName").value="";
      document.getElementById("comment").value="";
  }
  else
  {
    alert("你...太快了，等待"+countTime+"秒之后再发送.");
  }
        }
    }
