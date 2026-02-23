// Read input as text instead of raw bytes (Buffer)
process.stdin.setEncoding('utf8');

// Node is event-driven: this runs when input is available to read
process.stdin.on('readable', () => {
  const chunk = process.stdin.read();

  // read() can return null if nothing is ready yet
  if (chunk !== null) {
    // Write directly to stdout (lower-level than console.log)
    process.stdout.write('data: ' + chunk);
  }
});

// Fired when stdin is closed (EOF: Ctrl+D / end of pipe)
process.stdin.on('end', () => {
  process.stdout.write('end\n');
});
