/**
 * 
 * 		title:		DRAG STUFF - jQuery plugin
 * 
 *		author: 	Ovidiu Stefancu
 *					http:www.wpworks.net
 					
 *
 * 		info:		Custom function by wpworks.net 
 * 
 * 		ver:		1.1
 * 
 */

var WPWmodule = {
	id : "DragStuff", 
	version : 1, 
	func : function(theTrigger, toDrag, toDragWidth, dragWidthLimit, toDragHeight, dragHeightLimit, innerDrag){
		if(theTrigger.data('DragStuff')){
			theTrigger.data('DragStuff').reset();
			return theTrigger.data('DragStuff');
		}
	
		var $ = jQuery;
		var main = this;
		var handlerPositionX = 0;
		var handlerPositionY = 0;
		var oldMx = 0;
		var oldMy = 0;
		var mX = 0;
		var mY = 0;
		
		WPW.body = WPW.body || $('body');
		
		var dragDistance = 0;
		var dragDistanceV = 0;
		
		var dragOn = false;
		
		main.percent = 0;
	
		//handles the mouse drag&rotate events
		var touchEventsPreset = function(){
		
			theTrigger.bind("touchstart", function(e){
				e.preventDefault();
	  			var touchStart = e.originalEvent.touches[0] || e.originalEvent.changedTouches[0];
				
				oldMx = touchStart.pageX;
				oldMy = touchStart.pageY;
				dragOn = true;
				
				handlerPositionX = toDrag.position().left;
				handlerPositionY = toDrag.position().top;			
				
				dragStart();
	
				//return false;
			});
			
			WPW.body.bind("touchmove", function(e){
				if(!toDrag.data('dragging')){return;}
				
				e.preventDefault();
	  			var touch = e.originalEvent.touches[0] || e.originalEvent.changedTouches[0];
				mX = -oldMx + touch.pageX;
				mY = -oldMy + touch.pageY;
				oldMx = touch.pageX;
				oldMy = touch.pageY;
	
				handlerPositionX = handlerPositionX + mX;
				handlerPositionY = handlerPositionY + mY;
				dragDistance += Math.abs(mX);
				dragDistanceV += Math.abs(mY);
				
				testPosition();
				return false;
			});	
			
			var touchEnd = function(e){
				if(!toDrag.data('dragging')){return;}
				
				dragEnd(e);
			}
			
			WPW.body.bind("touchend", function(e){ touchEnd(e); });
			WPW.body.bind("touchcancel", function(e){ touchEnd(e); });
	
			theTrigger.bind("touchend", function(e){ touchEnd(e); });
			theTrigger.bind("touchcancel", function(e){ touchEnd(e); });
			
		};
		
		if(!WPW.isTouchDevice){
			theTrigger.mousedown(function(e){
				oldMx = e.pageX;
				oldMy = e.pageY;
				dragOn = true;
				dragStart();
				
				handlerPositionX = toDrag.position().left;
				handlerPositionY = toDrag.position().top;		
				
				WPW.body.mousemove(function(e){
					mX = -oldMx + e.pageX;
					mY = -oldMy + e.pageY;
					oldMx = e.pageX;
					oldMy = e.pageY;
					
					handlerPositionX = handlerPositionX + mX;
					handlerPositionY = handlerPositionY + mY;
					dragDistance += Math.abs(mX);
					dragDistanceV += Math.abs(mY);
					
					testPosition();
		
					return false;
				});
				
				$('html, body').mouseup(function(){
					WPW.body.unbind('mouseup');
					WPW.body.unbind('mousemove');
					dragEnd();
					return false;
				});
				theTrigger.mouseup(function(){
					WPW.body.unbind('mouseup');
					WPW.body.unbind('mousemove');
					dragEnd();
					return false;
				});
				return false;
			});
		}	
		
		var moveDragger = function(){
			if(toDrag.hasClass('fixed-mover')){return;}
			
			if(toDragWidth() > dragWidthLimit() || innerDrag){
				if(dragWidthLimit())toDrag.css('left', handlerPositionX + "px");	
			}
	
			if(dragHeightLimit()){
				toDrag.css('top', handlerPositionY + "px");
			}
	
			main.percent = handlerPositionX/(dragWidthLimit() - toDragWidth());
			theTrigger.trigger("DragPercent");
		} 
		
		main.manualRefresh = function(){
			handlerPositionX = toDrag.position().left;
			handlerPositionY = toDrag.position().top;
			testPosition();
		}
		
		var testPosition = function(){
			if(innerDrag){
				
				if(handlerPositionX < 0) handlerPositionX = 0;
				if(handlerPositionY < 0) handlerPositionY = 0;
				if(handlerPositionX > dragWidthLimit() - toDragWidth())handlerPositionX = dragWidthLimit() - toDragWidth();
				if(handlerPositionY > dragHeightLimit() - toDragHeight())handlerPositionY = dragHeightLimit() - toDragHeight();
			} else {
				
				if(handlerPositionX < dragWidthLimit() - toDragWidth()) handlerPositionX = dragWidthLimit() - toDragWidth();
				if(handlerPositionY < dragHeightLimit() - toDragHeight()) handlerPositionY = dragHeightLimit() - toDragHeight();
				if(handlerPositionX > 0)handlerPositionX = 0;
				if(handlerPositionY > 0)handlerPositionY = 0;				
			}
			
			moveDragger();
		}
		
		var dragStart = function(){
			toDrag.data('dragging', true);
			dragDistance = 0;
			dragDistanceV = 0;
			WPW.dragContainerMoved = false;
	
			theTrigger.trigger('wpwDragStart');
		}
		var dragEnd = function(e){
			toDrag.data('dragging', false);
			if(dragDistance > 10 || dragDistanceV > 10){
				WPW.dragContainerMoved = true;
			}
			
			if(WPW.isTouchDevice){
				var touch = e.originalEvent.touches[0] || e.originalEvent.changedTouches[0];
			
				var endX = touch.pageX;
				var endY = touch.pageY;
				
				theTrigger.data("dragEndX", endX);
				theTrigger.data("dragEndY", endY);
			}
	
			
			setTimeout(function(){WPW.dragContainerMoved = false}, 100);
			dragDistance = 0;
			dragDistanceV = 0;
			
			theTrigger.trigger('wpwDragEnd');
		}
		
		main.reset = function(){
			theTrigger.bind("RefreshDragger", function(){
				main.manualRefresh();
			});
			
			if(WPW.isTouchDevice)touchEventsPreset();
		}
		main.reset();
		theTrigger.data('DragStuff', this);
		
		//
	    }
	} 
	
var WPW = WPW || {}; 

if(!WPW[WPWmodule.id+"V"] || WPW[WPWmodule.id+"V"] < WPWmodule.version) {
	WPW[WPWmodule.id] = WPWmodule.func;
	WPW[WPWmodule.id+"V"] = WPWmodule.version;
} 

