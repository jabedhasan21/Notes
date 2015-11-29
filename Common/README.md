## Interview Questions
(1). **What is REST(representational state transfer) APIs ?**

*REST (REpresentational State Transfer) is a simple stateless architecture that generally runs over HTTP.*

(2).**What is object-oriented programming?**

*object-oriented programming (OOP), a style of coding in which related actions are grouped into classes to aid in creating more-compact, effective code.*

(3). **What is SQL Injection (SQLi)?**

SQL injection is a code injection technique, used to attack data-driven applications, in which malicious SQL statements are inserted into an entry field for execution (e.g. to dump the database contents to the attacker).

(4). **Inclusion Vulnerabilities: LFI and RFI**

+ Remote File Inclusion (RFI) attack.
+ Local File Inclusion (LFI) is similar to a Remote File Inclusion vulnerability.

File inclusion vulnerability is a type of vulnerability most often found on websites. It allows an attacker to include a file, usually through a script on the web server. The vulnerability occurs due to the use of user-supplied input without proper validation. This can lead to something as minimal as outputting the contents of the file or more serious events such as:
+ Code execution on the web server
+ Code execution on the client-side such as  JavaScript which can lead to other attacks such as cross site scripting (XSS)
+ Denial of service (DoS)
+ Data theft/manipulation

(5). **What is a csrf token ? what is it's importance and how does it work?**

*Cross-Site Request Forgery (CSRF or XSRF) attack.*

Cross-Site Request Forgery (CSRF) is a type of attack that occurs when a malicious Web site, email, blog, instant message, or program causes a user’s Web browser to perform an unwanted action on a trusted site for which the user is currently authenticated.

For example, this attack could result in a transfer of funds, changing a password, or purchasing an item in the user's context. In effect, CSRF attacks are used by an attacker to make a target system perform a function (funds Transfer, form submission etc.) via the target's browser without knowledge of the target user, at least until the unauthorized function has been committed.

(6) **Brute Force**

If you just want to get to the other side of a wall and don’t care how much noise you make, you can always use a machine gun to shoot bullets at it until there is nothing left, eventually the wall will fall and you can walk through unencumbered. That method is not unlike a Brute Force attack.

If there’s a form used to log in, then it’s possible to set up specialized scripts that continuously try different username and password combinations until a match is discovered, and the attacker gains access. This could be a brief attack, designed to check if the user has a weak password, and may only check the top 10 or top 100 most common passwords. It could also be a long-term targeted attack composed of lists of millions of passwords to try, and all the time in the world to wait for the right password to work.

More sophisticated Brute Force attacks compile password lists from keywords available on your website to test on your administrator login forms. The best way to protect yourself is by always using strong, unique passwords and supplementing your access control with Two Factor authentication.

(7).**Denial-of-service(DoS) and Distributed denial-of-service (DDoS) attack**

In computing, a denial-of-service (DoS) attack is an attempt to make a machine or network resource unavailable to its intended users, such as to temporarily or indefinitely interrupt or suspend services of a host connected to the Internet. A distributed denial-of-service (DDoS) is where the attack source is more than one–and often thousands–of unique IP addresses.

(8). **Service-Oriented Architecture (SOA) Definition**.

A service-oriented architecture (SOA) is an architectural pattern in computer software design in which application components provide services to other components via a communications protocol, typically over a network. The principles of service-orientation are independent of any vendor, product or technology.

(9). **What is nhibernate?**

  NHibernate is an object-relational mapping (ORM) solution for the Microsoft .NET platform. It provides a framework for mapping an object-oriented domain model to a traditional relational database.

  NHibernate is an ORM (Object Relational Mapper). Its purpose is to map objects in your OO application to tables in a database for persistence.

Why would you need it? Because it can save you from writing a lot of tedious ADO.NET code. Essentially it enhances developer productivity when developing CRUD applications, that is, applications whose main purpose is to Create, Read, Update, and Delete data in a database.

NHibernate is open source, and you need to realise that you are making your application dependent on third party libraries, whose long term goals may diverge from yours.

If you want the productivity of an ORM without introducing this dependency, consider Entity Framework, or Linq2SQL (noting that Linq2SQL locks you into SQL Server).

And finally if you don't need the productivity enhancement of an ORM, and you want absolute control, stick to plain old ADO.NET.
