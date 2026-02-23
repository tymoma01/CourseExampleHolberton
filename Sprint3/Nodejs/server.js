const { createServer } = require('node:http');

const server = createServer((req, res) => {
  res.statusCode = 200;
  res.setHeader('Content-Type', 'text/plain');
  res.end('Hello world\n');
});

server.listen(3000, '127.0.0.1', () => {
  console.log('Server on http://127.0.0.1:3000');
});


// Properly close a server
process.on('SIGINT', () => {
  console.log('\nSIGINT received: closing server...');
  server.close(() => {
    console.log('Closed. Exiting.');
    process.exit(0);
  });
});
