console.log('start');

process.nextTick(() => console.log('nextTick'));
setTimeout(() => console.log('setTimeout(0)'), 0);

console.log('end');



// First the synchronous code runs -> start, end 
// Then process.nextTick queue is executed before anything else
// Then are executed timers, I/O, promises
