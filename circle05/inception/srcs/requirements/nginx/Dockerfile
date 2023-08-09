# Start from a debian image base
FROM debian:buster

# Update and Install packages
RUN apt-get update -y && \
    apt-get install -y nginx openssl && \
    rm -rf /var/lib/apt/lists/*

# Create directory for SSL certificates
RUN mkdir -p /etc/nginx/ssl

# Generate self-signed SSL certificate and key
RUN openssl req -x509 -nodes -days 365 \
       -out /etc/nginx/ssl/zdevove.crt \
       -keyout /etc/nginx/ssl/zdevove.key \
       -subj "/C=FR/ST=Paris/L=Paris/O=42/OU=zdevove/CN=zdevove/"

# Copy the conf file inside nginx
COPY ./conf/nginx.conf /etc/nginx/nginx.conf

# Expose port 443 for HTTPS
EXPOSE 443

# Run NGINX
CMD ["nginx", "-g", "daemon off;"]

