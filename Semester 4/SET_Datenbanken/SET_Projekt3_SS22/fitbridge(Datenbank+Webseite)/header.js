function openWindow(url) {
    let windowFeatures = "popups";
    window.replace(url, url, windowFeatures);
}

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
  <div class="linkButton" style="right:52%" id="loginButton">
     <a href="login.html" onclick="openWindow('login.html')"><br>einloggen</a>
  </div>
  <div class="linkButton" style="right:31%">
    <a href="index.html" onclick="openWindow('index.html')"><br>home</a>
  </div>
  <div class="linkButton" style="right:10%">
    <a href="register.php" onclick="openWindow('register.html')"><br>registrieren</a>
  </div>
</div>
`;

document.body.appendChild(template.content);