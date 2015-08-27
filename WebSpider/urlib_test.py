import urllib2
response = urllib2.urlopen('http://wwww.baidu.com/')
html = response.read()
print html