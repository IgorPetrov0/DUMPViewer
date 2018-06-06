/**
 * 
 * 		title:		BEFORE/AFTER VIEWER - jQuery plugin
 * 
 *		author: 	Ovidiu Stefancu
 *					http:www.wpworks.net
 					
 *
 * 		info:		File available at http://codecanyon.net/user/wickedpixel
 * 
 * 		ver:		1.5.1 : 2013-jan-11
 * 
 */
var WPW=WPW||{};(function(e){var t=function(t,n){function u(){if(!s){s=true;r.infoBox.hide();r.infoBox.fadeIn();if(r.footer){r.footer.append(r.infoBox)}}e(".ba_info_text",r.tb).html(r.currentItem.info)}function a(){if(s){s=false;r.infoBox.fadeOut().detach()}}function f(){var t=r.items[r.currentIndex];var n=t.tb;r.currentItem=t;var i="easeInOutExpo";r.itemChangeBegin();e(r).animate({containerPosition:-r.currentIndex*100},{duration:500,easing:i,step:function(){r.container.css("left",r.containerPosition+"%")},complete:function(){r.container.css("left",r.containerPosition+"%");r.itemChangeEnd()}});r.checkForInfo()}var r=this;this.cfg=e.extend({},e.fn.wpwBAgallery.defaults,n);this.tb=e(t);this.currentIndex=0;this.currentItem=0;this.oldItem=0;this.items=[];this.nrItems=e("img",r.tb).length;this.footer=0;this.btnNext=0;this.btnPrev=0;var i=function(e,t){if(r.tb.attr("data-"+e)){r.cfg[e]=r.tb.attr("data-"+e);if(r.cfg[e]==="false"){r.cfg[e]=false}if(r.cfg[e]==="true"){r.cfg[e]=true}if(t){r.cfg[e]=parseInt(r.cfg[e],10)}}};var s=false;var o=/iPhone|iPod|iPad|Android/i.test(navigator.userAgent);WPW.isTouchDevice=o;i("width");i("height");i("disableIntro");i("alternateSkin");if(r.cfg.width==="0"||r.cfg.width===0||!r.cfg.width||r.cfg.width==="auto"){r.cfg.width=false}if(r.cfg.height==="0"||r.cfg.height===0||!r.cfg.height||r.cfg.height==="auto"){r.cfg.height=false}if(r.cfg.width){r.tb.css("width",r.cfg.width)}if(r.cfg.height){r.tb.css("height",r.cfg.height)}this.tb.addClass("ba_gallery");this.infoBox=e("<div class='ba_info'><div class='ba_info_bg_l'></div><div class='ba_info_text'></div><div class='ba_info_bg_r'></div></div>");this.container=e("<div class='ba_container'></div>");this.mask=e("<div class='ba_mask'></div>");r.tb.append(r.mask);r.mask.append(r.container);r.mask.css("width",r.cfg.width+"px");r.mask.css("height",r.cfg.height+"px");r.tb.css("width",r.cfg.width+"px");if(r.cfg.alternateSkin===true){r.tb.addClass("skin2")}e("img",r.tb).each(function(t){var n=e(this);var i=e("<div class='ba_item ba_"+t+"'></div>");if(t){i.css("left",t*100+"%");i.css("position","absolute")}r.container.append(i);i.append(n);var s=new WPW.baViewer(i,r,t);r.items.push(s)});this.itemChangeEnd=function(){r.oldItem=r.currentItem;r.currentItem.tb.trigger("SHOWBA")};this.itemChangeBegin=function(){if(r.oldItem){r.oldItem.tb.trigger("HIDEBA")}};this.checkForInfo=function(){if(r.currentItem.info){u()}else a()};r.containerPosition=0;if(r.nrItems>0){r.footer=e("<div class='ba_footer'><div class='ba_btn_prev'></div><div class='ba_btn_next'></div></div>");r.tb.append(r.footer);r.footer.css("width",r.cfg.width+"px");r.btnNext=e(".ba_btn_next",r.tb);r.btnPrev=e(".ba_btn_prev",r.tb);r.btnPrev.bind("click",function(){r.currentIndex-=1;if(r.currentIndex<0){r.currentIndex=r.nrItems-1}f();return false});r.btnNext.bind("click",function(){r.currentIndex+=1;if(r.currentIndex>r.nrItems-1){r.currentIndex=0}f();return false});if(r.nrItems<2){r.btnNext.remove();r.btnPrev.remove()}}f()};e.fn.wpwBAgallery=function(n){return this.each(function(){var r=e(this);if(r.data("wpwbagallery")){return}var i=new t(this,n);r.data("wpwbagallery",i)})};e.fn.wpwBAgallery.defaults={width:"auto",height:"auto",disableIntro:false,alternateSkin:false};e.fn._reverse=[].reverse;jQuery(document).ready(function(e){jQuery(".wpw-auto-init-ba").wpwBAgallery();WPW.ResizeEngine()})})(jQuery);WPW.baViewer=function(e,t,n){function g(e){var t=parseInt(c.data("visRatio")*f);p.css("left",t);c.css("left",t);if(i.img2){i.img2.css("left",-t-1)}}function y(e){var t=c.position();if(!e){c.data("visRatio",h.data("DragStuff").percent)}g()}function w(){o=false;var e="easeInOutExpo";if(i.owner.cfg.disableIntro==true){r(c.data()).delay(500).animate({visRatio:.5},{duration:600,step:function(){g(true)},easing:e,complete:function(){g(true)}})}else{r(c.data()).delay(500).animate({visRatio:1},{duration:600,step:function(){g(true)},easing:e,complete:function(){g(true)}}).animate({visRatio:0},{duration:600,step:function(){g(true)},easing:e,complete:function(){g(true)}}).animate({visRatio:.5},{duration:600,step:function(){g(true)},easing:e,complete:function(){g(true)}})}}function N(e){if(!e){return}var t;if(!e.pageX){t=h.data("dragEndX")-i.tb.offset().left}else{t=e.pageX-i.tb.offset().left}if(!t){return}var n=t/f;var s="easeInOutExpo";r(c.data()).delay(500).animate({visRatio:n},{duration:600,step:function(){g(true)},easing:s,complete:function(){}});return false}var r=jQuery;var i=this;this.tb=e;this.owner=t;var s=true;var o=true;var u=false;var a=false;var f=e.width();var l=e.height();var c=r('<div class="ba_controller"><div class="ba_controller_sign"></div></div>');var h=r('<div class="ba_wall" />');var p=r('<div class="ba_door" />');this.img1=r("img:first",i.tb);this.img2;var d=i.img1.attr("data-pic")||i.img1.attr("data-alt")||i.img1.attr("alt");var v=i.img1.attr("src");if(!d){d=v;v=""}this.info=i.img1.attr("title");if(v.length<2){return}this.tb.bind("SHOWBA",function(){x()});this.tb.bind("HIDEBA",function(){T()});c.data("visRatio",.5);var m=new WPW.DragStuff(h,c,function(){return 1},function(){return e.width()},function(){return 0},function(){return 0},true);h.bind("DragPercent",function(){y()});var b=function(){f=e.width();l=e.height();y(true)};var E=function(e){if(WPW.dragContainerMoved){return false}e.preventDefault();e.stopImmediatePropagation();e.stopPropagation();N(e);i.img2.bind("click",function(){return false})};var S=function(){if(!s&&!a){i.img2=r(new Image);i.img2.load(function(){h.click(function(e){E(e);return false});h.bind("wpwDragEnd",function(e){E(e);return false});onselectstart=function(){return false};a=true;if(o){w()}x()}).error(function(){alert("Error:\nImage not found on this path: "+v);a=true}).attr("src",v)}};var x=function(){if(!a){S();return}i.img2.prependTo(p);p.appendTo(i.tb);h.appendTo(i.tb);c.appendTo(h);if(!p.data("onScreen")){p.data("onScreen",true);p.fadeOut(0);p.fadeIn()}g()};var T=function(){if(p.data("onScreen")){return}p.fadeOut();p.data("onScreen",false)};i.img1.remove();i.img1=r(new Image);i.img1.load(function(){if(s){s=false;i.tb.prepend(i.img1);i.img1.bind("click",function(){return false});b();x()}}).error(function(){alert("Error:\nImage not found on this path: "+i.img1.data("img_path"))}).attr("src",d);r("body").bind("WindowResized",b)};WPW.localResizeEngine=function(){var e=this;var t=jQuery;e.resizeTimer=0;if(WPW.ResizeEngineStarter){return}WPW.ResizeEngineStarter=true;e.resizeEvent=function(){clearInterval(e.resizeTimer);e.resizeTimer=setInterval(function(){if(!WPW.body){if(t("body").length){WPW.body=t("body")}}WPW.body.trigger("WindowResized");clearInterval(e.resizeTimer)},100)};t(window).resize(function(){e.resizeEvent()})};WPW.ResizeEngine=WPW.ResizeEngine||WPW.localResizeEngine