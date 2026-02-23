// beforeExit is emitted ONLY when Node is about to exit because the event loop is empty

process.on('beforeExit', (code) => {
  console.log('[beforeExit]', code);
  setTimeout(() => console.log('timer scheduled in beforeExit ran'), 10); // Node does NOT exit
});

process.on('exit', (code) => {
  console.log('[exit]', code);
  setTimeout(() => console.log('this will NOT run'), 0); // If exit, then the timeout is ignored because the loop is shutting down
});

console.log('Done scheduling work.');
