/*
 * Copyright (C) 2011 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.example.android.basicglsurfaceview;

import android.app.Activity;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.Surface;
import android.view.WindowManager;

import java.io.File;


public class BasicGLSurfaceViewActivity extends Activity {

    public static BasicGLSurfaceView mView;

    @Override
    protected void onCreate(Bundle icicle) {
        super.onCreate(icicle);
        mView = new BasicGLSurfaceView(getApplication());
      //  setContentView(mView);
        
        setContentView(mView);
        testFunc();
       // setSurfaceBuffer(mView.getHolder().getSurface());
       // readSurface(mView.getHolder().getSurface());
       // BackThread thread = new BackThread();
       // thread.setDaemon(true);
       // thread.start();
    }
    
//    Handler mHandler = new Handler(){
//    	public void handleMessage(Message msg){
//    		Log.d("test","handleMessage");
//    		//synchronized (BasicGLSurfaceViewActivity.mView.getHolder())
//    		//{
//    			BasicGLSurfaceViewActivity.readSurface(BasicGLSurfaceViewActivity.mView.getHolder().getSurface());
//    		//}
//    				
// 
//    	}
//    };

    @Override
    protected void onPause() {
        super.onPause();
        mView.onPause();
    }

    @Override
    protected void onResume() {
        super.onResume();
        mView.onResume();
    }
    
    public native static void testFunc();
    public native static void readSurface(Surface surface);
    public native static void setSurfaceBuffer(Surface surface);
    
    static{
    	System.loadLibrary("nativeegl");
    }
    
//    class BackThread extends Thread{
//    	private int count = 0;
//    	public void run(){
//    		
//			try {
//				Thread.sleep(2000);
//			} catch (InterruptedException e) {
//				// TODO Auto-generated catch block
//				e.printStackTrace();
//			}
//    		
//    		BasicGLSurfaceViewActivity.setSurfaceBuffer(BasicGLSurfaceViewActivity.mView.getHolder().getSurface());
//    		
//    		while(true)
//    		{
//    			try {
//					Thread.sleep(2000);
//				} catch (InterruptedException e) {
//					// TODO Auto-generated catch block
//					e.printStackTrace();
//				}
//    			
//    			//BasicGLSurfaceViewActivity.setSurfaceBuffer(BasicGLSurfaceViewActivity.mView.getHolder().getSurface());
//    			//BasicGLSurfaceViewActivity.readSurface(BasicGLSurfaceViewActivity.mView.getHolder().getSurface());
//    			mHandler.sendEmptyMessage(0);
//    			count++;
//    			
//    			Log.d("test","BackThread count " + count);
//    			
//    			
//    		}
//    	}
//    }
    
}
