// Created by iWeb 3.0.4 local-build-20120811

setTransparentGifURL('Media/transparent.gif');function applyEffects()
{var registry=IWCreateEffectRegistry();registry.registerEffects({reflection_0:new IWReflection({opacity:0.50,offset:1.00}),stroke_0:new IWStrokeParts([{rect:new IWRect(-1,1,2,63),url:'HowToUse5_files/stroke.png'},{rect:new IWRect(-1,-1,2,2),url:'HowToUse5_files/stroke_1.png'},{rect:new IWRect(1,-1,570,2),url:'HowToUse5_files/stroke_2.png'},{rect:new IWRect(571,-1,2,2),url:'HowToUse5_files/stroke_3.png'},{rect:new IWRect(571,1,2,63),url:'HowToUse5_files/stroke_4.png'},{rect:new IWRect(571,64,2,2),url:'HowToUse5_files/stroke_5.png'},{rect:new IWRect(1,64,570,2),url:'HowToUse5_files/stroke_6.png'},{rect:new IWRect(-1,64,2,2),url:'HowToUse5_files/stroke_7.png'}],new IWSize(572,65)),shadow_0:new IWShadow({blurRadius:10,offset:new IWPoint(4.2426,4.2426),color:'#000000',opacity:0.750000})});registry.applyEffects();}
function hostedOnDM()
{return false;}
function onPageLoad()
{loadMozillaCSS('HowToUse5_files/HowToUse5Moz.css')
adjustLineHeightIfTooBig('id1');adjustFontSizeIfTooBig('id1');adjustLineHeightIfTooBig('id2');adjustFontSizeIfTooBig('id2');adjustLineHeightIfTooBig('id3');adjustFontSizeIfTooBig('id3');adjustLineHeightIfTooBig('id4');adjustFontSizeIfTooBig('id4');Widget.onload();fixAllIEPNGs('Media/transparent.gif');fixupIECSS3Opacity('id5');applyEffects()}
function onPageUnload()
{Widget.onunload();}
