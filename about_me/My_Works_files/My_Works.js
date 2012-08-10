// Created by iWeb 3.0.4 local-build-20120811

setTransparentGifURL('Media/transparent.gif');function applyEffects()
{var registry=IWCreateEffectRegistry();registry.registerEffects({reflection_0:new IWReflection({opacity:0.50,offset:1.00}),stroke_0:new IWPhotoFrame([IWCreateImage('My_Works_files/Freestyle_01.png'),IWCreateImage('My_Works_files/Freestyle_02.png'),IWCreateImage('My_Works_files/Freestyle_03.png'),IWCreateImage('My_Works_files/Freestyle_06.png'),IWCreateImage('My_Works_files/Freestyle_09.png'),IWCreateImage('My_Works_files/Freestyle_08.png'),IWCreateImage('My_Works_files/Freestyle_07.png'),IWCreateImage('My_Works_files/Freestyle_04.png')],null,2,0.639556,3.000000,3.000000,3.000000,3.000000,22.000000,24.000000,23.000000,25.000000,166.000000,222.000000,166.000000,222.000000,null,null,null,0.100000),shadow_0:new IWShadow({blurRadius:1,offset:new IWPoint(1.4142,1.4142),color:'#000000',opacity:0.440000})});registry.applyEffects();}
function hostedOnDM()
{return false;}
function onPageLoad()
{loadMozillaCSS('My_Works_files/My_WorksMoz.css')
fixAllIEPNGs('Media/transparent.gif');Widget.onload();fixupAllIEPNGBGs();applyEffects()}
function onPageUnload()
{Widget.onunload();}
