const { execFile } = require('node:child_process');

execFile('node', ['--version'], (err, stdout, stderr) => { // Subprocess is spawned (asynchronous)
  if (err) return console.error('error:', err.message);
  console.log('stdout:', stdout.trim());
  if (stderr) console.error('stderr:', stderr);
});

// Does not use a shell, args are array and is safer than using exec