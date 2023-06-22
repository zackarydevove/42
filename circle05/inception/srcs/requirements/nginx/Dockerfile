# Start from a debian image base
FROM debian:buster

# Update and Install packages, -y for automatic yes to any prompts
RUN apt-get update -y
RUN apt-get install -y nginx openssl 

# Create directory for SSL certificates
RUN mkdir -p /etc/nginx/ssl

# Generate self-signed SSL certificate and key
RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
       -out /etc/nginx/ssl/zdevove.crt \
       -keyout /etc/nginx/ssl/zdevove.key \
       -subj "/C=FR/ST=Paris/L=Paris/O=42/OU=zdevove/CN=zdevove/"

# Copy the conf file inside nginx
COPY ./conf/nginx.conf /etc/nginx/nginx.conf

# Create a run file to stock the temporary files from nginx
RUN mkdir -p /run/nginx

# Expose port 443 for HTTPS
EXPOSE 443

# Run NGINX
CMD ["nginx", "-g", "daemon off;"]

