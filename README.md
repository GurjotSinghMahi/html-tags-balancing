A simple exercise for testing a stack is determining whether a set of html tags in html file are well-formed/Balanced or not.
What exactly is meant by that? In the case of a pair of html tags (<html>, </html>) for an expression to be well formed, consider the following table.
<html><title></title></html> <- Well formed and balanced
<html><title><title></html> <- Not Balanced

Warning: This program is not designed to handle unclosing tags like <br>
