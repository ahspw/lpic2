server {
	listen 80 default_server;
	listen [::]:80 default_server;
	root /var/www/html;
	index index.html index.htm index.nginx-debian.html;
	server_name lpic2.com;
	location /search {
		proxy_pass https://www.google.com/;
	}
}
