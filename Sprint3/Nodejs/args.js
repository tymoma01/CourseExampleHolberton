const args = process.argv.slice(2);
const nums = args.map(Number);

if (nums.length === 0 || nums.some(Number.isNaN)) {
  console.error('Usage: node args.js <n1> <n2> ...');
  process.exit(9);
}

const sum = nums.reduce((a, b) => a + b, 0);
console.log(sum);
