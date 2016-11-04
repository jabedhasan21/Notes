# Activity Lifecycle
---
+ ### Lifecycle 1

![1](images/basic-lifecycle.png)
+ ### Lifecycle 2
![2](images/Android-Activity-Lifecycle.png)

# 1. Starting an Activity
---
![1](images/basic-lifecycle-create.png)

Unlike other programming paradigms in which apps are launched with a main() method, the Android system initiates code in an `Activity` instance by invoking specific callback methods that correspond to specific stages of its lifecycle. There is a sequence of callback methods that start up an activity and a sequence of callback methods that tear down an activity.


### Understand the Lifecycle Callbacks

Depending on the complexity of your activity, you probably don't need to implement all the lifecycle methods. However, it's important that you understand each one and implement those that ensure your app behaves the way users expect. Implementing your activity lifecycle methods properly ensures your app behaves well in several ways, including that it:
+ Does not crash if the user receives a phone call or switches to another app while using your app.
+ Does not consume valuable system resources when the user is not actively using it.
+ Does not lose the user's progress if they leave your app and return to it at a later time.
+ Does not crash or lose the user's progress when the screen rotates between landscape and portrait orientation.

**However, only three of these states can be static.**
+ Resumed
+ Paused
+ Stopped

### Specify Your App's Launcher Activity

When the user selects your app icon from the Home screen, the system calls the `onCreate()` method for the Activity in your app that you've declared to be the "launcher" (or "main") activity.

The main activity for your app must be declared in the manifest with an `<intent-filter>` that includes the `MAIN` action and `LAUNCHER` category. For example:

```
<activity android:name=".MainActivity" android:label="@string/app_name">
    <intent-filter>
        <action android:name="android.intent.action.MAIN" />
        <category android:name="android.intent.category.LAUNCHER" />
    </intent-filter>
</activity>
```

If either the `MAIN` action or `LAUNCHER` category are not declared for one of your activities, then your app icon will not appear in the Home screen's list of apps.

### Create a New Instance

Most apps include several different activities that allow the user to perform different actions. Whether an activity is the main activity that's created when the user clicks your app icon or a different activity that your app starts in response to a user action, the system creates every new instance of Activity by calling its `onCreate()` method.

You must implement the `onCreate()` method to perform basic application startup logic that should happen only once for the entire life of the activity.

The `onCreate()` method shows some code that performs some fundamental setup for the activity, such as declaring the user interface (defined in an XML layout file), defining member variables, and configuring some of the UI.

```
TextView mTextView; // Member variable for text view in the layout

@Override
public void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);

    // Set the user interface layout for this Activity
    // The layout file is defined in the project res/layout/main_activity.xml file
    setContentView(R.layout.main_activity);

    // Initialize member TextView so we can manipulate it later
    mTextView = (TextView) findViewById(R.id.text_message);
}
```
+ Once the onCreate() finishes execution, the system calls the onStart() and onResume() methods in quick succession.
+ Your activity never resides in the Created or Started states.
+ Technically, the activity becomes visible to the user when onStart() is called, but onResume() quickly follows and the activity remains in the Resumed state until something occurs to change that, such as when a phone call is received, the user navigates to another activity, or the device screen turns off.

+  The three main callbacks that the system calls in sequence when creating a new instance of the activity: `onCreate()`, `onStart()`, and `onResume()`. Once this sequence of callbacks complete, the activity reaches the Resumed state where users can interact with the activity until they switch to a different activity.

### Destroy the Activity
While the activity's first lifecycle callback is onCreate(), its very last callback is onDestroy(). The system calls this method on your activity as the final signal that your activity instance is being completely removed from the system memory.

Most apps don't need to implement this method because local class references are destroyed with the activity and your activity should perform most cleanup during `onPause()` and `onStop()`. However, if your activity includes background threads that you created during `onCreate()` or other long-running resources that could potentially leak memory if not properly closed, you should kill them during `onDestroy()`.

```
@Override
public void onDestroy() {
    super.onDestroy();  // Always call the superclass

    // Stop method tracing that the activity started during onCreate()
    android.os.Debug.stopMethodTracing();
}
```

The system calls `onDestroy()` after it has already called `onPause()` and `onStop()` in all situations except one: when you call `finish()` from within the `onCreate()` method.

# 2. Pausing and Resuming an Activity
---
![](images/basic-lifecycle-paused.png)

When a semi-transparent activity obscures your activity, the system calls onPause() and the activity waits in the Paused state (1). If the user returns to the activity while it's still paused, the system calls onResume() (2).



when apps run in multi-window mode, only one of the apps has the focus at any time; the system pauses all other apps.
As long as the activity is still partially visible but currently not the activity in focus, it remains paused.
+ As your activity enters the paused state, the system calls the onPause() method on your Activity
 + If the user returns to your activity from the paused state, the system resumes it and calls the onResume() method.

## Pause Your Activity
When the system calls onPause() for your activity, it technically means your activity is still partially visible, but most often is an indication that the user is leaving the activity and it will soon enter the Stopped state. You should usually use the onPause() callback to:
+ Check if the activity is visible; if it is not, stop animations or other ongoing actions that could consume CPU
+ Commit unsaved changes, but only if users expect such changes to be permanently saved when they leave (such as a draft email).
+ Release system resources, such as broadcast receivers, handles to sensors (like GPS), or any resources that may affect battery life while your activity is paused and the user does not need them.

For example, if your application uses the `Camera`, the `onPause()` method is a good place to release it.

```
@Override
public void onPause() {
    super.onPause();  // Always call the superclass method first

    // Release the Camera because we don't need it when paused
    // and other activities might need to use it.
    if (mCamera != null) {
        mCamera.release();
        mCamera = null;
    }
}
```

Generally, you should not use onPause() to store user changes (such as personal information entered into a form) to permanent storage. The only time you should persist user changes to permanent storage within onPause() is when you're certain users expect the changes to be auto-saved (such as when drafting an email). However, you should avoid performing CPU-intensive work during onPause(), such as writing to a database, because it can slow the visible transition to the next activity (you should instead perform heavy-load shutdown operations during onStop()).

+ When your activity is paused, the Activity instance is kept resident in memory and is recalled when the activity resumes. You don’t need to re-initialize components that were created during any of the callback methods leading up to the Resumed state.

### Resume Your Activity
When the user resumes your activity from the Paused state, the system calls the `onResume()` method.
+ **Be aware that the system calls this method every time your activity comes into the foreground, including when it's created for the first time.**

+ you should implement `onResume()` to initialize components that you release during `onPause()`

```
@Override
public void onResume() {
    super.onResume();  // Always call the superclass method first

    // Get the Camera instance as the activity achieves full user focus
    if (mCamera == null) {
        initializeCamera(); // Local method to handle camera init
    }
}
```

# 3. Stopping and Restarting an Activity
---
![](images/basic-lifecycle-stopped.png)

**Figure.**
+ When the user leaves your activity, the system calls onStop() to stop the activity (1).
+ If the user returns while the activity is stopped, the system calls onRestart() (2),
+  quickly followed by onStart() (3)
+  and onResume() (4).
+  Notice that no matter what scenario causes the activity to stop, the system always calls onPause() before calling onStop().



Properly stopping and restarting your activity is an important process in the activity lifecycle that ensures your users perceive that your app is always alive and doesn't lose their progress. There are a few of key scenarios in which your activity is stopped and restarted:
+ The user opens the Recent Apps window and switches from your app to another app.
+ The user performs an action in your app that starts a new activity. The current activity is stopped when the second activity is created. If the user then presses the Back button, the first activity is restarted.
+ The user receives a phone call while using your app on his or her phone.

The Activity class provides two lifecycle methods, `onStop()` and `onRestart()`, which allow you to specifically handle how your activity handles being stopped and restarted.

Because the system retains your Activity instance in system memory when it is stopped, it's possible that you don't need to implement the onStop() and onRestart() (or even onStart() methods at all. For most activities that are relatively simple, the activity will stop and restart just fine and you might only need to use onPause() to pause ongoing actions and disconnect from system resources.

### Stop Your Activity

When your activity receives a call to the onStop() method, it's no longer visible and should release almost all resources that aren't needed while the user is not using it. Once your activity is stopped, the system might destroy the instance if it needs to recover system memory. In extreme cases, the system might simply kill your app process without calling the activity's final onDestroy() callback, so it's important you use onStop() to release resources that might leak memory.

Although the onPause() method is called before onStop(), you should use onStop() to perform larger, more CPU intensive shut-down operations, such as writing information to a database.

```
@Override
protected void onStop() {
    super.onStop();  // Always call the superclass method first

    // Save the note's current draft, because the activity is stopping
    // and we want to be sure the current note progress isn't lost.
    ContentValues values = new ContentValues();
    values.put(NotePad.Notes.COLUMN_NAME_NOTE, getCurrentNoteText());
    values.put(NotePad.Notes.COLUMN_NAME_TITLE, getCurrentNoteTitle());
}
```

### Start/Restart Your Activity
When your activity comes back to the foreground from the stopped state, it receives a call to onRestart(). The system also calls the onStart() method, which happens every time your activity becomes visible (whether being restarted or created for the first time).

The onRestart() method, however, is called only when the activity resumes from the stopped state, so you can use it to perform special restoration work that might be necessary only if the activity was previously stopped, but not destroyed.

It's uncommon that an app needs to use onRestart() to restore the activity's state, so there aren't any guidelines for this method that apply to the general population of apps. However, because your onStop() method should essentially clean up all your activity's resources, you'll need to re-instantiate them when the activity restarts. Yet, you also need to instantiate them when your activity is created for the first time (when there's no existing instance of the activity). For this reason, you should usually use the onStart() callback method as the counterpart to the onStop() method, because the system calls onStart() both when it creates your activity and when it restarts the activity from the stopped state.

For example, because the user might have been away from your app for a long time before coming back it, the onStart() method is a good place to verify that required system features are enabled:
```
@Override
protected void onStart() {
    super.onStart();  // Always call the superclass method first

    // The activity is either being restarted or started for the first time
    // so this is where we should make sure that GPS is enabled
    LocationManager locationManager =
            (LocationManager) getSystemService(Context.LOCATION_SERVICE);
    boolean gpsEnabled = locationManager.isProviderEnabled(LocationManager.GPS_PROVIDER);

    if (!gpsEnabled) {
        // Create a dialog here that requests the user to enable GPS, and use an intent
        // with the android.provider.Settings.ACTION_LOCATION_SOURCE_SETTINGS action
        // to take the user to the Settings screen to enable GPS when they click "OK"
    }
}

@Override
protected void onRestart() {
    super.onRestart();  // Always call the superclass method first

    // Activity being restarted from stopped state
}
```
# 4. Recreating an Activity
---

![](images/basic-lifecycle-savestate.png)


**Figure**. As the system begins to stop your activity, it calls onSaveInstanceState() (1) so you can specify additional state data you'd like to save in case the Activity instance must be recreated. If the activity is destroyed and the same instance must be recreated, the system passes the state data defined at (1) to both the onCreate() method (2) and the onRestoreInstanceState() method (3).



There are a few scenarios in which your activity is destroyed due to normal app behavior,
+ such as when the user presses the Back button
+ or your activity signals its own destruction by calling finish().
+ The system may also destroy your activity if it's currently stopped and hasn't been used in a long time
+ or the foreground activity requires more resources so the system must shut down background processes to recover memory.


When your activity is destroyed because the user presses Back or the activity finishes itself, the system's concept of that Activity instance is gone forever because the behavior indicates the activity is no longer needed. However, if the system destroys the activity due to system constraints (rather than normal app behavior), then although the actual Activity instance is gone, the system remembers that it existed such that if the user navigates back to it, the system creates a new instance of the activity using a set of saved data that describes the state of the activity when it was destroyed. The saved data that the system uses to restore the previous state is called the "instance state" and is a collection of key-value pairs stored in a Bundle object.

**Caution:** Your activity will be destroyed and recreated each time the user rotates the screen. When the screen changes orientation, the system destroys and recreates the foreground activity because the screen configuration has changed and your activity might need to load alternative resources (such as the layout).

To save additional data about the activity state, you must override the onSaveInstanceState() callback method. The system calls this method when the user is leaving your activity and passes it the Bundle object that will be saved in the event that your activity is destroyed unexpectedly. If the system must recreate the activity instance later, it passes the same Bundle object to both the onRestoreInstanceState() and onCreate() methods.

### Save Your Activity State
```
static final String STATE_SCORE = "playerScore";
static final String STATE_LEVEL = "playerLevel";
...

@Override
public void onSaveInstanceState(Bundle savedInstanceState) {
    // Save the user's current game state
    savedInstanceState.putInt(STATE_SCORE, mCurrentScore);
    savedInstanceState.putInt(STATE_LEVEL, mCurrentLevel);

    // Always call the superclass so it can save the view hierarchy state
    super.onSaveInstanceState(savedInstanceState);
}
```


### Restore Your Activity State
```
@Override
protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState); // Always call the superclass first

    // Check whether we're recreating a previously destroyed instance
    if (savedInstanceState != null) {
        // Restore value of members from saved state
        mCurrentScore = savedInstanceState.getInt(STATE_SCORE);
        mCurrentLevel = savedInstanceState.getInt(STATE_LEVEL);
    } else {
        // Probably initialize members with default values for a new instance
    }
    ...
}
```


Instead of restoring the state during onCreate() you may choose to implement onRestoreInstanceState(), which the system calls after the onStart() method. The system calls onRestoreInstanceState() only if there is a saved state to restore, so you do not need to check whether the Bundle is null:

```
public void onRestoreInstanceState(Bundle savedInstanceState) {
    // Always call the superclass so it can restore the view hierarchy
    super.onRestoreInstanceState(savedInstanceState);

    // Restore state members from saved instance
    mCurrentScore = savedInstanceState.getInt(STATE_SCORE);
    mCurrentLevel = savedInstanceState.getInt(STATE_LEVEL);
}
```
