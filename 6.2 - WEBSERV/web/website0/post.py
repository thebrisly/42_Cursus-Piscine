import requests

url = 'http://localhost:8888/img/'
files = {'file': open('albert-camus.jpg', 'rb')}

response = requests.post(url, files=files)
print(response.text)
