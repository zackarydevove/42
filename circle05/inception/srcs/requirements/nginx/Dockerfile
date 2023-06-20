# Start from a debian image base
FROM Debian:buster

# Update and Install packages, -y for automatic yes to any prompts
RUN apt-get update
RUN apt-get install -y nginx openssl 

# Create directory for SSL certificates
RUN mkdir /etc/nginx/ssl

# Copy the nginx.conf file from your local machine to the docker image.
COPY conf/nginx.conf /etc/nginx/nginx.conf

# Generate self-signed SSL certificate and key
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -subj \
    "/C=FR/ST=Paris/L=Paris/O=42/CN=localhost" \
    -keyout /etc/nginx/ssl/nginx-selfsigned.key \
    -out /etc/nginx/ssl/nginx-selfsigned.crt

# Expose port 443 for HTTPS
EXPOSE 443

# Run NGINX
CMD ["nginx", "-g", "daemon off;"]

