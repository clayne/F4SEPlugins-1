﻿package  {
	import F4SE.ICodeObject;
	import flash.display.MovieClip;
    import flash.display.Loader;
    import flash.net.URLRequest;
	import flash.text.Font;
	import flash.events.Event;
	import flash.ui.Keyboard;
	
	public class PNIOPAMenu extends MovieClip implements ICodeObject {
      	private var f4seCodeObject;
		private var inputMap:Object = new Object();
		
		public function PNIOPAMenu() {
        	super();
			
			Shared.Root = this;
			
			var font_urlRequest:URLRequest = new URLRequest();
			font_urlRequest.url = "fonts_en.swf";
			
			var font_loader:Loader = new Loader();
			font_loader.contentLoaderInfo.addEventListener(Event.COMPLETE, onLoadComplete);
			font_loader.load(font_urlRequest);
		}

		public function onF4SEObjCreated(codeObject:*) : void {
			this.f4seCodeObject = codeObject;
         	Shared.F4SEPlugin = this.f4seCodeObject.plugins.PseudoNIOPA;
			
			if (Shared.MainFont)
				Shared.F4SEPlugin.Initialize();
		}
		
		private function onLoadComplete(e:Event):void {
			var font_class:Class = e.target.applicationDomain.getDefinition("$MAIN_Font") as Class;
			Shared.MainFont = new font_class;
			Font.registerFont(font_class);
			
			if (Shared.F4SEPlugin)
				Shared.F4SEPlugin.Initialize();
		}
		
		private function IsDirectionKey(keyCode:uint) : Boolean {
			switch (keyCode) {
				case Keyboard.UP:
				case Keyboard.DOWN:
				case Keyboard.LEFT:
				case Keyboard.RIGHT:
					return true;
			}
			return false;
		}
		
		private function ShouldHandleKey(keyCode:uint, isDown:Boolean) : Boolean {
			if (keyCode == 0xFF)
				return false;
				
			if (!IsDirectionKey(keyCode))
				return isDown ? false : true;
				
			if (isDown) {
				var date = new Date();
				if (!inputMap.hasOwnProperty(keyCode)) {
					inputMap[keyCode] = date.time + 250;
					return true;
				}
				else {
					if (date.time - inputMap[keyCode] <= 50) {
						return false;
					}
					else {
						inputMap[keyCode] = date.time;
						return true;
					}
				}
			}
			else {
				delete inputMap[keyCode];
				return false;
			}
		}
		
		public function ProcessKeyEvent(keyCode:uint, isDown:Boolean) : void {
			if (!ShouldHandleKey(keyCode, isDown))
				return;
			
			if (keyCode == Keyboard.TAB) {
				Shared.CloseMenu(1);
			}
			else {
				if (Shared.CurrentView)
					Shared.CurrentView.ProcessKeyEvent(keyCode);
			}
		}
		
		public function ShowMainMenu(selectedMenu:String, selectedGroup:String, selectedNode:String) : void {
			var mainView = new MainView(selectedNode);
			Shared.ShowView(mainView);
			
			if (selectedMenu) {
				var selectNodeGroupView = new SelectNodeGroupView(selectedNode);
				Shared.ShowView(selectNodeGroupView);
				
				if (selectedMenu == "SELECTNODE") {
					var selectNodeView = new SelectNodeView(selectedGroup, selectedNode);
					Shared.ShowView(selectNodeView);
				}
				else if (selectedMenu == "SEARCHNODE") {
					var searchNodeView = new SearchNodeView(selectedNode);
					Shared.ShowView(searchNodeView);
				}
			}
		}
	}
}