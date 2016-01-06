# Document Object Model (DOM)
+ What is the DOM?
  + The Document Object Model (DOM) is a programming interface for HTML, XML and SVG documents.
  + It provides a structured representation of the document (a tree) and it defines a way that the structure can be accessed from programs so that they can change the document structure, style and content.
  + The DOM provides a representation of the document as a structured group of nodes and objects that have properties and methods.
  + Nodes can also have event handlers attached to them, and once that event is triggered the event handlers get executed.
  + Essentially, it connects web pages to scripts or programming languages.

  + Though often accessed using JavaScript, the DOM itself is not a part of the JavaScript language, and it can be accessed by other languages, though this is much less common.

+ A Web page is a document. This document can be either displayed in the browser window, or as the HTML source. But it is the same document in both cases. The Document Object Model (DOM) provides another way to represent, store and manipulate that same document. The DOM is a fully object-oriented representation of the web page, and it can be modified with a scripting language such as JavaScript.

# DOM and JavaScript
+ In the beginning, JavaScript and the DOM were tightly intertwined, but eventually they evolved into separate entities.
+ The page content is stored in DOM and may be accessed and manipulated via JavaScript, so that we may write this approximative equation:

API (web or XML page) = DOM + JS (scripting language)

+ The DOM was designed to be independent of any particular programming language, making the structural representation of the document available from a single, consistent API.

+ Though we focus exclusively on JavaScript in this reference documentation, implementations of the DOM can be built for any language, as this Python example demonstrates:
  ```
  # Python DOM example
  import xml.dom.minidom as m
  doc = m.parse("C:\\Projects\\Py\\chap1.xml");
  doc.nodeName # DOM property of document object;
  p_list = doc.getElementsByTagName("para");
  ```
+ **How Do I Access the DOM?**

    + You don't have to do anything special to begin using the DOM.
    + Different browsers have different implementations of the DOM, and these implementations exhibit varying degrees of conformance to the actual DOM standard (a subject we try to avoid in this documentation), but every web browser uses some document object model to make web pages accessible to script.


# Important Data Types
+ The following table briefly describes these data types.
  ```
  document
  element
  etc...

  ```
+ The Document interface describes the common properties and methods for any kind of document. Depending on the document's type (e.g. HTML, XML, SVG, …).

# Reference
 + [DOM](https://developer.mozilla.org/en-US/docs/Web/API/Document_Object_Model/Introduction)
