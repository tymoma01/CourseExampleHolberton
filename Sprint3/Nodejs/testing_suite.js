const assert = require('node:assert');

// Mocha test suite
describe('async demo', function () {

  // A single test case
  // The presence of `done` tells Mocha this test is asynchronous
  it('waits for done()', function (done) {

    // Simulate async work (timer, I/O, etc.)
    setTimeout(() => {

      // Assertion: throws if false
      assert.strictEqual(2 + 2, 4);

      // Signal to Mocha that the async test is finished
      done();
    }, 50);
  });
});


// What is Mocha?
// Mocha is a JavaScript test runner for Node.js.
// In practical terms:
// It executes test files
// It provides a structure (describe, it)
// It decides when a test passes or fails
// It handles asynchronous code correctly

// Mocha itself does not check values — it just runs tests.
// That’s why we use an assertion library (assert) to say what should be true.

// npx mocha testing_suite.js 