## Laravel Interview Questions

### Laravel 5.1 Changes

+ Event Broadcasting.
+ Middleware Parameters.
+ Testing Overhaul.
+ Model Factories.
+ Artisan Improvements.
+ Folder Structure.
+ Encryption.

In previous versions of Laravel, encryption was handled by the mcrypt PHP extension. However, beginning in Laravel 5.1, encryption is handled by the openssl extension, which is more actively maintained.

## Questions

(1). **What is Accessors & Mutators?**

Accessors and mutators allow you to format Eloquent attributes when retrieving them from a model or setting their value. For example, you may want to use the Laravel encrypter to encrypt a value while it is stored in the database, and then automatically decrypt the attribute when you access it on an Eloquent model.

+ [**Accessors & Mutators**](http://laravel.com/docs/5.1/eloquent-mutators#accessors-and-mutators)

(2). **What happend in 'App\Http\Requests'  Directory?**

(3). **How to create a scope in Laravel?**

Scopes allow you to define common sets of constraints that you may easily re-use throughout your application.

To define a scope, simply prefix an Eloquent model method with *scope*

+ [**eloquent-query-scopes**](http://laravel.com/docs/5.1/eloquent#query-scopes)

(4). **How to create group routes with prefix  in Laravel?**
