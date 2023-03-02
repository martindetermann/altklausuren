const template = document.createElement('template');

template.innerHTML = `
<style>
  .mainBanner{
    position:fixed;
    width:100%;
    height: 20%;
    top:0;
    left:0;
    background-color:black;
  }
  .mainBanner p{
    position:inherit;
    left:1%;
    vertical-align: middle;
    color:greenyellow;
    font-family: Arial;
    font-size: 50px;
    font-weight:bold;
  }
  .linkButton{
    position:absolute;
    width:20%;
    height:40%;
    top:30%;
    background-color: greenyellow;
    border-color:black;
  }
  .linkButton a{
    position:absolute;
    text-align: center;
    width:100%;
    height:100%;
    font-family:Arial;
    font-variant:normal;
    font-weight:bold;
    text-decoration-line:none;
    color:black;
  }
</style>
<div class="mainBanner">
  <p class="titleMain">Fitness24</p>
  <div class="linkButton" style="right:52%">
    <a href="inc/logout_inc.php"><br>logout</a>
  </div>
  <div class="linkButton" style="right:31%">
    <a href="appointment.php"><br>Termin Buchen</a>
  </div>
  <div class="linkButton" style="right:10%">
    <a href="message.php"><br>Nachricht Senden</a>
  </div>
</div>
`;

document.body.appendChild(template.content);