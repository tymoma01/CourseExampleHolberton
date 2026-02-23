const { spawn } = require('node:child_process');

// Spawn a real OS process (non-blocking)
// This starts another Node.js process running `node --version`
const child = spawn('node', ['--version']);

// stdout is a stream: data arrives in chunks
child.stdout.on('data', (data) => {
  process.stdout.write(`stdout: ${data}`);
});

// stderr is also a separate stream
child.stderr.on('data', (data) => {
  process.stderr.write(`stderr: ${data}`);
});

// Emitted when the process has exited AND all stdio streams are closed
child.on('close', (code) => {
  console.log(`exit code: ${code}`);
});

// Emitted if the process could not be spawned at all
child.on('error', () => {
  console.error('Failed to start subprocess.');
});
